#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
// /etc/security/limits.conf
int main(){
	int i=0;
	pid_t pid;
	do{
		pid = fork();
		switch(pid){
			case -1:
				printf("El número máximo de procesos es de: %d\n", p);
				exit(-1);
			break;
			case 0:
				exit(1);
			break;
			default:
				i++;
			break;
		}
	}while(pid);
	return 0;
}