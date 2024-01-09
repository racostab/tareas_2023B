/*
 * Alumno: Daniel Montes Guerrero
 * Compilar: g++ system.cpp
 */

#include<iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		system("cat system.cpp");
	}
	else{
		cout << "Soy system.cpp" << endl;
	}
	return 0;
}