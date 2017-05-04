#ifndef user_management_H
#define user_management_H

typedef struct user_l{
	int id;
	int sock;
	char *username;
	struct user_l *next;
} user_l;

user_l *create_user_list();
int insert_user(user_l **l, char *username, int sock);
int remove_user(user_l **l, int id);
int valid_username(user_l *l, char *username);
int getsock(user_l **l, int *sock_aux);

#endif // user_management_H
