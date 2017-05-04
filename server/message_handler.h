#include "msg.pb-c.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>


char *receive_chat(Chat *chat);
void receive_query(Query *query, int *imin, int *imax);
void send_chat(int sock, char *chat, int id_msg);
void send_query(int sock, char **chat, int idmin, int idmax);
Index *receive_choice(int sock, char * name);
int receive_login(int sock, char **nome);
void send_status(int sock, int status);
int init_socket();
