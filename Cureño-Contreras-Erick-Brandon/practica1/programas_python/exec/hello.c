/*
	Autor: Cureño Contreras Erick Brandon
	Compilacion: gcc -o hello hello.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	char *endptr;
	int numero = strtol(argv[1], &endptr, 10);
	printf("Hello: %d\n",numero);
	return 0;
}

