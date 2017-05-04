#include "message_handler.h"


char *receive_chat(Chat *chat){ 
	if(chat == NULL){
		fprintf(stderr, "mensagem invalida chat\n"); 
		exit(-1);
	} 
	return strdup(chat->text);
}
void receive_query(Query *query, int *imin, int *imax){ 
	if(query == NULL){
		fprintf(stderr, "mensagem invalida query\n");
		exit(-1);
	}
	*imin=query->idmin;
	*imax=query->idmax;
}

void send_chat(int sock, char *chat, int id_msg){
	Chat msg = CHAT__INIT;
	uint8_t *buff;

	msg.has_id = 1;
	msg.id = id_msg;
	msg.text = (char *) strdup(chat);
	
	size_t size_chat =  chat__get_packed_size(&msg);
	buff = malloc(size_chat);

	chat__pack(&msg, buff);

	send(sock, buff , size_chat, 0);
	free(buff);
}

void send_query(int sock, char **chat, int idmin, int idmax){
	Chat **msg;
	Query msg_query = QUERY__INIT;
	uint8_t *buff;
	int i, aux_free;

	msg = malloc(sizeof(Chat*) * (idmax-idmin+1));
	if(chat == NULL){ //if this happens, it was an invalid request from client
		msg[0] = malloc(sizeof(Chat));
		chat__init(msg[0]);
		msg[0]->id = 0;
		msg[0]->has_id = 1;
		msg[0]->text = strdup("INVALID");
		msg_query.n_query_data = 1;
		aux_free=0;
	} else{ //valid query
		aux_free=1;
		for(i = 0; i <= idmax-idmin; i ++){
			msg[i] = malloc(sizeof(Chat));
			chat__init(msg[i]);
			msg[i]->id = i+idmin;
			msg[i]->has_id = 1;
			msg[i]->text = strdup(chat[i]);
		}
		msg_query.n_query_data = idmax-idmin+1;
	}
	msg_query.query_data = msg;

	size_t size_query = query__get_packed_size(&msg_query);
	buff = malloc(size_query);
	query__pack(&msg_query, buff);
	send(sock, buff , size_query, 0);
	free(buff);
	if(aux_free==1){
		for(i = 0; i <= idmax-idmin; i ++){
			free(msg[i]);		
		}
	}else free(msg[0]);
	free(msg);	
}

Index *receive_choice(int sock, char * name){
	Index *msg_index;
	uint8_t buff[100];
	
	size_t len = recv(sock, buff, 100, 0 );
	msg_index = index__unpack(NULL, len, buff);
	
	if(msg_index == NULL){ 
		return NULL;
	}
	
	return msg_index;
}

int receive_login(int sock, char **nome){ 
	Login *msg;
	uint8_t buff[100];

	size_t len = recv(sock, buff, 100, 0 );

	Index *msg_index = index__unpack(NULL, len, buff);
	if(msg_index == NULL || msg_index->choice != CHOICE_TYPE__LOGIN){
		return 1;
	}
	msg = msg_index->login_info;
	if(msg == NULL){ 
		fprintf(stderr, "mensagem invalida login\n");
		exit(-1);
	}
	*nome = strdup( msg->username);
	login__free_unpacked(msg, NULL); 
	return 0;
}

void send_status(int sock, int status){
	Status msg = STATUS__INIT;
	uint8_t *buff;
	msg.value = status;

	buff = malloc( status__get_packed_size(&msg));
	status__pack(&msg, buff);
	send(sock, buff , status__get_packed_size(&msg), 0);
	
	free(buff);
	return;
}

int init_socket(){
	int sock;
	struct sockaddr_in addr;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		printf("Couldn't create socket\n");
		exit(-1);
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(3000);		
    addr.sin_addr.s_addr = INADDR_ANY;
	
	bind(sock, (struct sockaddr *)  &addr, sizeof(addr));
	perror("bind");
	
	
	if(listen(sock, 10) == -1){
		perror("listen");
		printf("Couldn't listen socket\n");
		exit(-1);
	}
	
	return sock;
}
