/*
 * Alumno: Daniel Montes Guerrero
 * Compilar: g++ max_procesos.cpp
 */

#include<iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main(){
	pid_t pid;
	int i = 0;
	for(i = 0; 1; i++){
		pid = fork();
		if(pid == 0){
			break;
		}
		else if(pid < 0){
			cout << "El numero de procesos creados fue: " << i << endl;
			break;
		}
		else{
			cout << "Soy el padre creando el proceso: " << i + 1 << endl;
		}
	}
	return 0;
}
