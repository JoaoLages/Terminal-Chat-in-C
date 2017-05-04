#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>

#include "log_system.h"

int main(){
	int *verify_quit;
	char *buffer=NULL;
	size_t len;
	int mem_fd = shm_open("/shared_mem", O_CREAT | O_RDWR, 0666);

	ftruncate(mem_fd, sizeof(int));
	verify_quit = mmap(0, sizeof(int), PROT_WRITE, MAP_SHARED, mem_fd, 0);

	printf("Choose one of the following:\nQUIT - closes the server\nLOG - prints the log at stdin\nEXIT - close\n");
	while(1){
		if(getline(&buffer, &len, stdin)<10){
			if(strcmp(buffer, "QUIT\n")==0){ // Terminates server and relauncher properly
				*verify_quit = 1;
			}
			if(strcmp(buffer, "LOG\n")==0){ // Prints all the LOG 
				print_log();
			}
			if(strcmp(buffer, "EXIT\n")==0){ // Exits
				break;
			}
		}
	}
	exit(0);
}
