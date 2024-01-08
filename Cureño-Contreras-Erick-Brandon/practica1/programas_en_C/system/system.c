/*
	Autor: Cureño Contreras Erick Brandon
	Compilación: gcc -o system system.c
	Ejecución: ./system
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
		printf("Soy system\n");
	}
	return 0;
}
