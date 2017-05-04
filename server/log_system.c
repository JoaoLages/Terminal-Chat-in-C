#include "log_system.h"

void log_chat(int id, char *user){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "message id(%d) sent by %s on %s", id, user, asctime(gmtime(&result)));
	fclose(fp);
}
	
void log_clientlogin(char *user){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "user %s has logged in on %s", user, asctime(gmtime(&result)));
	fclose(fp);
}

void log_disconnect(char *user){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "user %s has disconnected on %s", user, asctime(gmtime(&result)));
	fclose(fp);
}

void log_query(char *user, int idmin, int idmax){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "user %s requested chats between id(%d) and id(%d) on %s", user, idmin, idmax, asctime(gmtime(&result)));
	fclose(fp);
}
	
void log_servercrash(){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "server crashed on %s", asctime(gmtime(&result)));
	fclose(fp);
}

void log_serveron(){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "server turned on %s", asctime(gmtime(&result)));
	fclose(fp);
}

void log_serveroff(){
	FILE *fp;
	time_t result = time(NULL);
	
	fp = fopen(LOG_FILE, "a");
	fprintf(fp, "server turned off on %s", asctime(gmtime(&result)));
	fclose(fp);
}

void print_log(){
	FILE *fp;
	char line[200];
	
	fp = fopen(LOG_FILE, "r");
	if(fp == NULL) return;
	
	while(fgets(line, 200, fp) != NULL){
		printf("%s", line);
	}
	fclose(fp);
}
