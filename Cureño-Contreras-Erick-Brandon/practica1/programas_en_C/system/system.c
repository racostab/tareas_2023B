/*
	Autor: Cure�o Contreras Erick Brandon
	Compilaci�n: gcc -o system system.c
	Ejecuci�n: ./system
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
	pid = fork();
	if(pid == 0){
		system("Cat system");
	}
	else{
		printf("Soy system\n");
	}
	return 0;
}
