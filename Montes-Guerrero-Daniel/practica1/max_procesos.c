/*
 * Alumno: Daniel Montes Guerrero
 * Compilar: gcc max_procesos.c
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	int i = 0;
	for(i = 0; 1; i++){
		pid = fork();
		if(pid == 0){
			printf("Soy el hijo %d con padre %d\n", getpid(), getppid());
			break;
		}
		else if(pid < 0){
			printf("El numero de procesos creados fue: %d\n", i);
			break;
		}
		else{
			printf("Soy el padre %d creando el proceso: %d\n", getpid(), i + 1);
		}
	}
	return 0;
}
