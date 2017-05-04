#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define LOG_FILE "log.txt"

typedef struct log_block{
    int type;
    char *user;
    int id, idmin, idmax;
} log_block;

void log_chat(int id, char *user);
void log_clientconnect();
void log_clientlogin(char *user);
void log_disconnect(char *user);
void log_query(char *user, int idmin, int idmax);
void log_servercrash();
void log_serveron();
void log_serveroff();
void print_log();
