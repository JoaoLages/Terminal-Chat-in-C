#include "message_processing.h"

void send_ids(int sock, int idmin, int idmax){ //send ids of query to server
	Query msg = QUERY__INIT;
	Index msg_index = INDEX__INIT;
	uint8_t *buff;
	msg.has_idmin = 1;
	msg.has_idmax = 1;
	
	msg.idmin = idmin;
	msg.idmax = idmax;
	msg_index.choice = CHOICE_TYPE__QUERY;
	msg_index.query_limits = &msg;
	
	size_t size_index =  index__get_packed_size(&msg_index);
	buff = malloc(size_index);

	index__pack(&msg_index, buff);

	send(sock, buff , size_index, 0);
	free(buff);
}

void send_username(int sock, char *username){ //send username to server
	Login msg = LOGIN__INIT;
	Index msg_index = INDEX__INIT;
	uint8_t *buff;

	msg.username = (char *) strdup(username);
	msg_index.choice = CHOICE_TYPE__LOGIN;
	msg_index.login_info = &msg;
	
	size_t size_index =  index__get_packed_size(&msg_index);
	buff = malloc(size_index);

	index__pack(&msg_index, buff);

	send(sock, buff , size_index, 0);
	free(buff);
}

void send_chat(int sock, char *chat){ // send chat message to server
	Chat msg = CHAT__INIT;
	Index msg_index = INDEX__INIT;
	uint8_t *buff;
	
	msg.text = (char *) strdup(chat);
	msg_index.choice = CHOICE_TYPE__CHAT;
	msg_index.chat_data = &msg;
	
	size_t size_index =  index__get_packed_size(&msg_index);
	buff = malloc(size_index);

	index__pack(&msg_index, buff);

	send(sock, buff , size_index, 0);
	free(buff);
}

int valid_username(int sock){  //receives validation of username from server
	Status *msg;
	uint8_t buff[100];
	
	size_t len = recv(sock, buff, 100,0);
	msg = status__unpack(NULL, len, buff);
	if(msg == NULL){
		fprintf(stderr, "mensagem invalida\n");
		return -1;
	}
	if(msg->value !=1){
		printf("Username already taken, choose another\n");
	}
	return msg->value;
}

int receive_chat(int *sock, char** text, int *id, int *has_login, int*invalid, char*ip){ //receive broadcast chat from server
	Chat *msg;
	uint8_t buff[100]; 
	
	size_t len = recv(*sock, buff, 100, MSG_PEEK);
	if(len <= 0) {
		close(*sock);
		*sock=connect_socket(ip);
		*has_login = 0;
		*invalid = 0;
		printf("Connection went down, please enter LOGIN 'username' again \n");
		return 0;
	}
	msg = chat__unpack(NULL, len, buff);
	if(msg == NULL){ 
		fprintf(stderr, "mensagem invalida\n");
	} else{
		len = recv(*sock, buff, 100, 0);
		*text = strdup(msg->text);
		*id = msg->id;
	}
	return 1;
}

void receive_query(int sock){ //receive query chats from server
	Query *msg;
	uint8_t buff[1000000]; //100*10000
	int i;
	size_t len = recv(sock, buff, 1000000, 0); //100 = CHAT_SIZE limit, 10000= Query limit
	msg = query__unpack(NULL, len, buff);
	
	if(strcmp(msg->query_data[0]->text, "INVALID") == 0){
		printf("Invalid query\n");
	} else{
		for(i = 0; i < msg->n_query_data; i ++){
			printf("%d: %s\n", msg->query_data[i]->id, msg->query_data[i]->text);
		}
	}
	query__free_unpacked(msg,NULL);
}

int connect_socket(char*ip){ //connect socket to given ip
	int sock;
	struct sockaddr_in server_addr;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock== -1){
		printf("Couldn't create socket\n");
		exit(-1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3000);		
	if(inet_aton(ip, & server_addr.sin_addr)==0){
		printf("Invalid ip, try again\n");
		return -1;
		}	
	
		
	if(connect(sock, ( struct sockaddr *) &server_addr, sizeof(server_addr)) == -1){
		printf("Server is not available, try again later\n");
		close(sock);
		exit(-1);
	}
	
	return sock;
}	
