#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "chat_storage.h"

list *create_list(){ // creates list
	list * element = malloc(sizeof(list));
		
	element->id = 0;
	element->chat_msg = NULL;
	element->next = NULL;
	
	return element;
}

void push(list **chat_stg, char *content){ // adds message to list
	int id = (*chat_stg)->id;
	
	list * n_element = malloc(sizeof(list));
	n_element->next = *chat_stg;
	*chat_stg = n_element;
	(*chat_stg)->id = id + 1;
	(*chat_stg)->chat_msg = strdup(content);
}


int retrieve_msg(list *chat_stg, int id, char **msg){ // returns 1 and the chat in sucess, 0 if not
	
	if(chat_stg->id != id){
		if(chat_stg->id < id) return 0; //id not found
		chat_stg = chat_stg->next;
		if(retrieve_msg(chat_stg, id, msg)==0) return 0;
		else return 1;
	}
	*msg=strdup(chat_stg->chat_msg);
	return 1;//success
}

