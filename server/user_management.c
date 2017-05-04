#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "user_management.h"

user_l *create_user_list(){
	user_l *element = malloc(sizeof(user_l));
		
	element->id = 0;
	element->sock = -1;
	element->username = NULL;
	element->next = NULL;
	
	return element;
}

int insert_user(user_l **l, char *username, int sock){
	int id = (*l)->id;
	
	user_l *n_element = malloc(sizeof(user_l));
	n_element->next = *l;
	*l = n_element;
	(*l)->id = id + 1;
	(*l)->username = strdup(username);
	(*l)->sock = sock;
	
	return id + 1;
}

int remove_user(user_l **l, int id){
	user_l *aux1 = malloc(sizeof(user_l));
	user_l *aux2 = malloc(sizeof(user_l));
	aux1 = *l;
	aux2 = (*l)->next;
	
	if(aux1->id == id){
		*l = (*l)->next;
		free(aux1);
		return 1;//success
	}
	
	while(aux2->id != id){
		if(aux2->id < id) return 0; //id not found
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	
	if(aux2->next != NULL){
		aux1->next = aux2->next;
		free(aux2);
	} else{
		aux1->next = NULL;
		free(aux2);
	}	
	return 1;//success
}
int getsock(user_l **l, int *sock_aux){
	if((*l)->sock == -1) return 0;
	*sock_aux=(*l)->sock;
	(*l)=(*l)->next;
	return 1;
	}

int valid_username(user_l *l, char *username){
	
	while(l->next != NULL){
		if(strcmp(username, l->username) == 0) return 0;
		l = l->next;
	}
	return 1;
}
	
