#include <pthread.h>
#include <semaphore.h>

#include "chat_storage.h"
#include "log_system.h"
#include "user_management.h"
#include "message_handler.h"

#define SERVER_ON 1
#define SERVER_OFF 2
#define SERVER_CRASH 3
#define LOGIN 4
#define CHAT 5
#define QUERY 6
#define DISCONNECT 7
#define PRINT_LOG 8

pthread_mutex_t data_userlist = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t data_chatlist = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t data_idmsg = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t data_log = PTHREAD_MUTEX_INITIALIZER;
pthread_t thread_log_system_id;
int id_msg=1, *verify_quit;
int sock_fd;
list *chat_storage;
user_l *l;
log_block lb;
sem_t *sem;

void *thread_log_system(void *arg){
	log_block l = *(log_block*)arg;
	
	pthread_mutex_lock(&data_log);
	switch(l.type){
		case SERVER_ON:
		log_serveron();
		break;
		
		case SERVER_OFF:
		log_serveroff();
		break;
		
		case SERVER_CRASH:
		log_servercrash();
		break;
		
		case LOGIN:
		log_clientlogin(l.user);
		break;
		
		case CHAT:
		log_chat(l.id, l.user);
		break;
		
		case QUERY:
		log_query(l.user, l.idmin, l.idmax);
		break;
		
		case DISCONNECT:
		log_disconnect(l.user);
		break;
		
		case PRINT_LOG:
		print_log();
		break;
	}
	pthread_mutex_unlock(&data_log);
	pthread_exit(NULL);
}

void *thread_verify_quit(void *arg){ // verifies if admin wants to QUIT server properly

	while(1){
		sleep(1);  // no need to waste resources
		if(*verify_quit==1){
			
			/*update log_system with server_off message*/
			log_serveroff();
			
			close(sock_fd);
			exit(7);
		}
	}
	pthread_exit(NULL);
}
int verify_username(int sock, char *name){ //sees if username already in use or not
	int a = valid_username(l, name);
	send_status(sock, a);
	return a;
}

void *thread_accept(void *sock){ //client thread
	int new_sock1, ret, i2;
	int n_user;
	char *nl;
	Index *msg;
	char *chat, *aux_name;
	char **query_data;
	int idmin, idmax, i, aux, sock_aux, n_query;
	
	new_sock1 = *((int*)sock);
	sem_post(sem);
	
	user_l *auxl = malloc(sizeof(user_l));
	do{
		ret = receive_login(new_sock1, &nl); //1st message is always a login
		if(ret == 1) { 
			printf("client disconnected\n");
			pthread_exit(NULL);
		}
	} while(!verify_username(new_sock1, nl));
	
	pthread_mutex_lock(&data_userlist);
	n_user = insert_user(&l, nl, new_sock1);
	pthread_mutex_unlock(&data_userlist);
	
	/*update log_system with login message*/
	lb.type = LOGIN;
	lb.user = strdup(nl);
	pthread_create(&thread_log_system_id, NULL, thread_log_system, (void *) &lb);
	
	while(1){
		msg = receive_choice(new_sock1, nl); // receives the index type of message
		if(msg == NULL){
			printf("client %s disconnected\n", nl);
			
			/*update log_system with disconnect message*/
			lb.type = DISCONNECT;
			lb.user = strdup(nl);
			pthread_create(&thread_log_system_id, NULL, thread_log_system, (void *) &lb);
			pthread_mutex_lock(&data_userlist);
			remove_user(&l, n_user); //remove username from username list
			pthread_mutex_unlock(&data_userlist);
			pthread_exit(NULL);
		}
		switch(msg->choice){
			
			case CHOICE_TYPE__LOGIN://LOGIN
			break;
			
			case CHOICE_TYPE__CHAT://CHAT
			aux_name = strdup(nl);
			chat = receive_chat(msg->chat_data); 
			strcat(aux_name, ": ");
			strcat(aux_name, chat);
			
			auxl=l;	
			pthread_mutex_lock(&data_chatlist);
			while(getsock(&auxl, &sock_aux) != 0){ // BROADCAST
				send_chat(sock_aux, aux_name, id_msg);
			}
			pthread_mutex_unlock(&data_chatlist);
			/*update log_system with chat message*/
			lb.type = CHAT;
			lb.user = strdup(nl);
			lb.id = id_msg;
			pthread_create(&thread_log_system_id, NULL, thread_log_system, (void *) &lb);
			pthread_mutex_lock(&data_idmsg);
			id_msg ++;
			pthread_mutex_unlock(&data_idmsg);
			pthread_mutex_lock(&data_chatlist);
			push(&chat_storage, chat); //stores message
			pthread_mutex_unlock(&data_chatlist);
			break;
			
			case CHOICE_TYPE__QUERY://QUERY
			receive_query(msg->query_limits, &idmin, &idmax); //receives ids
			query_data = malloc((idmax - idmin + 1) * sizeof(char*));
			pthread_mutex_lock(&data_chatlist);
			if(retrieve_msg(chat_storage, idmin, &chat)==0) send_query(new_sock1, NULL, idmin, idmax); //invalid query
			else{
				n_query=0;
				for(i = 0; i <= (idmax-idmin); i ++){
					aux = retrieve_msg(chat_storage, idmin + i, &chat); //1 if message exists, 0 if not
					if(aux == 0) {
						n_query=i-1;
						i=(idmax-idmin)+1; // break for
					}else{
						n_query=i;
						query_data[i] = strdup(chat);
					}
				}
				send_query(new_sock1, query_data, idmin, idmin+n_query);
				for(i2=0; i2<n_query; i2++){
					free(query_data[i2]);
				}
			}
			pthread_mutex_unlock(&data_chatlist);
			free(query_data);
			/*update log_system with query message*/
			lb.type = QUERY;
			lb.user = strdup(nl);
			lb.idmin = idmin;
			lb.idmax = idmax;
			pthread_create(&thread_log_system_id, NULL, thread_log_system, (void *) &lb);
			break;
		}
	}
	pthread_exit(NULL);
}

void clientlaunch(int *sock){
	pthread_t thread_id; 
	pthread_create(&thread_id, NULL, thread_accept, sock); //client thread
}

void *thread_crash_recovery(void *arg){ // thread that sees if relauncher is dead
	int ppid= *(int*)arg;
	int status;
	int f_ret;
	char argv_buffer[10];
	char *myargv[4];
	
	do{ //waits for relauncher to change status
		sleep(1); // no need to waste resources
		status=kill(ppid,0);
	}while(status!=-1);	
	while(1){
	

		do{
			f_ret = fork();
			if(f_ret == 0){ //launches relauncher as child process
				sprintf (argv_buffer, "%d", getppid());
				myargv[0]=strdup(argv_buffer);
				myargv[1] = strdup("binded");
				sprintf (argv_buffer, "%d", sock_fd);
				myargv[2] = strdup(argv_buffer);
				myargv[3]= NULL;
				execve("relauncher", myargv, NULL);
			} else{ // waits for relauncher to change status
				wait(&status);				
			}
		} while(WIFSIGNALED(status));
	}
		
	pthread_exit(NULL);
}

int main(int argc, char *argv[], char *envp[]){
	pthread_t thread_crash_recovery_id;
	pthread_t thread_verify_quit_id;
	fd_set readfds;
	int new_sock;
	int ppid= atoi(argv[0]);
	char* myargv[4];
	char buffer[100];
	char argv_buffer[10];
	int mem_fd = shm_open("/shared_mem", O_CREAT | O_RDWR, 0666);
	ftruncate(mem_fd, sizeof(int));
	
	if(argv[1]==NULL || strcmp(argv[1], "not_binded")==0){ //Creates socket 1st time only !
		sock_fd = init_socket();
	}else{
		sock_fd=atoi(argv[2]); // gets the created socket 
	}
	
	verify_quit = mmap(0, sizeof(int), PROT_WRITE, MAP_SHARED, mem_fd, 0);
	*verify_quit = 0;
	
	myargv[0]=strdup("./relauncher");
	myargv[1] = strdup("binded");
	sprintf (argv_buffer, "%d", sock_fd);
	myargv[2] = strdup(argv_buffer);
	myargv[3]= NULL;
	if(strcmp(argv[0], "./server")==0) execve("relauncher", myargv, NULL); //launch relauncher
	
	pthread_create(&thread_crash_recovery_id, NULL, thread_crash_recovery, &ppid); //thread that sees if relauncher died
	l = create_user_list();
	chat_storage = create_list();
	sem = sem_open("/sem", O_CREAT, 0600, 1);

	/*update log_system with server_on message*/
	lb.type = SERVER_ON;
	pthread_create(&thread_log_system_id, NULL, thread_log_system, (void *) &lb);
	
	pthread_create(&thread_verify_quit_id, NULL, thread_verify_quit, NULL); // thread that sees if admin wants to QUIT the server
	
	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	FD_SET(sock_fd, &readfds);
	while(1){	
		
		select(sock_fd +1, &readfds, NULL,NULL, NULL);
		if(FD_ISSET(0, &readfds)){ //for inputs at stdin
			fgets(buffer, 100, stdin);
			printf("Run ./readstdin to input commands\n");
		}
		if(FD_ISSET(sock_fd, &readfds)){ //for client creation
			sem_wait(sem);
			new_sock = accept(sock_fd, NULL, NULL);
			fcntl(new_sock, F_SETFD, FD_CLOEXEC); //closes socket when server closes properly
			clientlaunch(&new_sock); //creates client thread (no limit)
		}
		
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(sock_fd, &readfds);
	}
	exit(0);
}
