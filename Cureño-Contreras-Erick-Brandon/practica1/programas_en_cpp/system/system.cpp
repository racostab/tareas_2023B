/*
	Autor: Cureño Contreras Erick Brandon
	Compilación: g++ -o system system.cpp
	Ejecución: ./system
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
