/*
	Autor: Cureño Contreras Erick Brandon
	Compilacion: gcc -o fork fork.c
	Ejecución: ./fork
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid = fork();
	switch(pid){
		case -1:
			printf("Error\n");
		break;
		case 0:
			printf("Codigo del hijo %d\n", getpid());
		break;
		default:
			printf("Padre %d\n", getpid());
		break;
	}
	return 0;
}
