/*
	Autor: Cure�o Contreras Erick Brandon
	Compilaci�n: g++ -o system system.cpp
	Ejecuci�n: ./system
*/
#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main() {
    pid_t pid;
	pid = fork();
	if(pid == 0){
		system("ls");
	}
	else{
		printf("Soy system.c\n");
	}
}
