/*
    $ g++ -o system system.cpp
    $ ./system
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
		printf("System padre\n");
	}
}