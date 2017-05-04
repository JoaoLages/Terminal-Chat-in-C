#ifndef chat_storage_H
#define chat_storage_H

typedef struct list{
	int id;
	char *chat_msg;
	struct list *next;
} list;

list *create_list();
void push(list **chat_stg, char *content);
int retrieve_msg(list *chat_stg, int id, char **msg);

#endif // chat_storage_H
