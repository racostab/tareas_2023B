/*
	Autor: Cureño Contreras Erick Brandon
	Compilacion: gcc -o exec1 exec1.c
	Ejecución: ./exec1
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
	int ret;
	char *arg1 = "10";
	char *pathname = "hello";
	printf("proceso\n");
	ret = execl(pathname, pathname, arg1, NULL);
	printf("Adios\n");
	return 0;
}
