#include <pthread.h>

#include "message_processing.h"
#include "input_processing.h"

int has_login =0;
int invalid = 0;
char *ip = NULL;

void * thread_receivemessage(void *sock){ //receives broadcast messages (including self messages)
	char *chat;
	int id, aux;
	int sock_fd=*(int*) sock;

	while(1){
		aux=receive_chat(&sock_fd, &chat, &id, &has_login, &invalid, ip);
		if(aux==1) printf("\n%s, id= %d\n", chat, id);
	}
	pthread_exit(NULL);
}

int main(){	
	pthread_t thread_rcvmsg;
	int option, end = 0;
	char *line = malloc(LINE_SIZE*sizeof(char));
	char *username = malloc(LINE_SIZE*sizeof(char));
	char *chat = malloc(CHAT_SIZE*sizeof(char));
	int idmin, idmax;
	size_t len;
	int sock_fd;
	
	printf("Which ip do you want to connect to?\nIf local ip, just type LOCAL\n");
	do{
		while(getline(&ip, &len, stdin)>20) printf("Invalid ip, try again\n");
		if(strcmp(ip, "LOCAL\n")==0) ip=strdup("127.0.0.1");
		sock_fd = connect_socket(ip); //connect socket with given ip
	}while(sock_fd==-1);
	pthread_create(&thread_rcvmsg, NULL, thread_receivemessage, &sock_fd); // launches thread to receive messages
	printf("\nSucess!\nChoose one of the following options:\n");
	printf("LOGIN 'username'\nDISC\nCHAT 'string'\nQUERY 'id_min' 'id_max'\n");
	printf("Your command: ");
	while(!end){
		option = option_select(&line);
		if(option == 1){//login case
			if(has_login == 0){
				do{
					get_username(line, &username, invalid);
					send_username(sock_fd, username); 
					invalid = 1;
				} while(!valid_username(sock_fd));
				printf("You are now logged\n");
				has_login = 1;
			} else{
				printf("You have already logged in, try a different command\n");
			}
		}
		if(option == 2){//disc case
			end = 1;
		}
		if(option == 3){//chat case
			if(has_login == 1){
				get_chat(line, &chat);
				send_chat(sock_fd, chat);
			}else{
				printf("You must first login before chatting\n");
			}
		}
		if(option == 4){//query case
			if(has_login == 1){
				get_ids(line, &idmin, &idmax);
				send_ids(sock_fd, idmin, idmax);
				receive_query(sock_fd);
			} else{
				printf("You must first login before sending queries\n");
			}
		}
	}
	exit(0);
}
