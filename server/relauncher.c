#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <pthread.h>

#include "log_system.h"


int main(int argc, char *argv[], char *envp[]){
	int f_ret, status, i = 0;
	int mem_fd = shm_open("/shared_mem", O_CREAT | O_RDWR, 0666);
	char argv_buffer[10];
	char *myargv[4];
	int server_id= atoi(argv[0]);
	int *verify_quit;
	
	ftruncate(mem_fd, sizeof(int));
	verify_quit = mmap(0, sizeof(int), PROT_WRITE, MAP_SHARED, mem_fd, 0);
	
	while(1){
		if(strcmp(argv[0], "./relauncher")==0){ //initialize server if equal argv[0]   
			do{
				f_ret = fork();
				if(f_ret == 0){ //launches server as child process
					sprintf (argv_buffer, "%d", getppid());
					myargv[0]=strdup(argv_buffer);
					if(i == 0) myargv[1] = strdup(argv[1]);
					else myargv[1] = strdup("binded");
					myargv[2]=strdup(argv[2]);
					myargv[3]= NULL;
					execve("server", myargv, NULL);
				}else{ //waits for child to change status
					wait(&status);
					log_servercrash(); // updates log with server crash message
					i = 1;
				}
			} while(WEXITSTATUS(status) != 7); // Terminate all processes
			break;
		}else{ //server already initialized
			do{// waits for server to change status
				sleep(1); // no need to waste resources
				status=kill(server_id,0);
			}while(status!=-1);
			if(*verify_quit == 1) break; // Terminate all processes
			log_servercrash(); // updates log with server crash message
			argv[0]=strdup("./relauncher");
		}
	}
	exit(0);
}
