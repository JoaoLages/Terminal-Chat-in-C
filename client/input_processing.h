#ifndef INPUT_PROCESSING
#define INPUT_PROCESSING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAT_SIZE 93
#define LINE_SIZE 99
#define COMMAND_SIZE 10

int option_select(char **parameters);
void get_username(char *line, char **username, int invalid);
void get_chat(char *line, char **chat);
void get_ids(char *line, int *idmin, int *idmax);

#endif
