#include "input_processing.h"

int option_select(char **parameters){ //gets line from stdin and gets option 
	int option;
	char *line =NULL, *command;
	command = malloc(COMMAND_SIZE*sizeof(char));
    size_t len;
    int num;
	
	while(1){
		num=getline(&line, &len, stdin);
		if(num>LINE_SIZE){ //limited chat 
			 printf("Command too long, try again\n");
			 option = 0;
			 break;
		 }
		if(sscanf(line, "%s", command) == 1){ //choose command option
			if(strcmp(command, "LOGIN") == 0){
				option = 1;
				break;
			}
			if(strcmp(command, "DISC") == 0){
				option = 2;
				break;
			}
			if(strcmp(command, "CHAT") == 0){
				option = 3;
				break;
			}
			
			if(strcmp(command, "QUERY") == 0){
				option = 4;
				break;
			}
		}
		printf("Invalid command\n");
		option=0;
	}
	strcpy(*parameters, line);
	free(command);
	free(line);
	return option;
}

void get_username(char *line, char **username, int invalid){ //gets valid username from stdin
	char *line2;
	line2 = NULL;
	size_t len;
	int aux=0;
	
	if(invalid == 0){ //1st time
		if(sscanf(line, "%s %s", *username, *username) != 2){
			printf("Username was not provided, try again\n"); 
			printf("Username: ");
			while(getline(&line2, &len, stdin)>CHAT_SIZE){ //limited message
				printf("Username too long, try again\n");
				}
			sscanf(line2, "%s", *username);
		
			while(strcmp(*username, "LOGIN")==0 || aux>CHAT_SIZE){ //limited message and username can't be a "\n"
				printf("Invalid username, try again\nUsername:");
				aux=getline(&line2, &len, stdin);
				sscanf(line2, "%s", *username);
				}
		}
	} else{
		printf("Username: ");
		while(getline(&line2, &len, stdin)>CHAT_SIZE){
				printf("Username too long, try again\n");
				}
		sscanf(line2, "%s", *username);
	}
	free(line2);
}

void get_chat(char *line, char **chat){ //gets chat from stdin
	int text_len = strlen(line);	
	char garbage_char[10];
	
	if(text_len > 5){
		sscanf(line, "%s %[^\n]\n",garbage_char,*chat); //gets all chat after "CHAT"
	} else{
		printf("You haven't include a chat string, try again\n");
		printf("Message: ");
		fgets(*chat, CHAT_SIZE, stdin);
		strtok(*chat, "\n"); //clears \n
	}
}

void get_ids(char *line, int *idmin, int *idmax){ //Gets id's for query
	int id1, id2;
	char line2[LINE_SIZE];
	char garbage[10]; 
	
	if(sscanf(line, "%s %d %d",garbage, &id1, &id2) !=3 || id1<=0 || id2<=0 || abs(id2-id1)>10000){ //limit query
		do{
			printf("2 valid IDs were not provided, try again\n");
			printf("IDs: ");
			fgets(line2, LINE_SIZE, stdin);
		} while(sscanf(line2, "%d %d", &id1, &id2) != 2 || id1<=0 || id2<=0 || abs(id2-id1)>10000);  //limit query
	}
	if(id1 <= id2){ //gets id's properly
		*idmin = id1;
		*idmax = id2;
	} else{
		*idmin = id2;
		*idmax = id1;
	}
}
