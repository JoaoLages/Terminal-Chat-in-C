#include <sys/un.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/un.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "msg.pb-c.h"

void send_ids(int sock, int idmin, int idmax);
void send_username(int sock, char *username);
void send_chat(int sock, char *chat);
int receive_chat(int *sock, char** text, int *id, int *has_login, int*invalid, char*ip);
void receive_query(int sock);
int valid_username(int sock);
int connect_socket(char*ip);
