/*
 * Alumno: Daniel Montes Guerrero
 * Compilar: g++ exec.cpp
 */

#include<iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		execl("/bin/cat", "cat", "./exec.cpp", 0);
	}
	else{
		cout << "Soy exec.cpp" << endl;
	}
	return 0;
}
