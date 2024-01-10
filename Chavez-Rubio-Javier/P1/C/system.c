/*
    $ gcc -o system system.c
    $ ./system
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
	pid = fork();

	if(pid == 0){
		system("ls");
	}
	else{
		printf("System padre\n");
	}

	return 0;
}