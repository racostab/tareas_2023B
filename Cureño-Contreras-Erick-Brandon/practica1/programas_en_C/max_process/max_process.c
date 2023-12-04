#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
// /etc/security/limits.conf
int main(){
	int i, p=0;
	pid_t pid;
	printf("PID: %d\n",getpid());
	do{
		pid = fork();
		switch(pid){
			case -1:
				printf("Error %d\n", p);
				exit(-1);
			break;
			case 0:
				exit(1);
			break;
			default:
				p++;
			break;
		}
	}while(pid);
	return 0;
}
