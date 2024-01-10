/*
    $ g++ -o fork fork.cpp
    $ ./fork
*/

#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    
    switch (pid) {
        case -1:
            std::cerr << "Error de creación" << std::endl;
            break;
        case 0:
            std::cout << "Código del hijo: " << getpid() << std::endl;
            break;
        default:
            std::cout << "Código del padre: " << getpid() << std::endl;
            break;
    }
    
    return 0;
}
