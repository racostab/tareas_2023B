#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    switch (pid) {
        case -1:
            std::cerr << "Error" << std::endl;
            break;
        case 0:
            std::cout << "Codigo del hijo " << getpid() << std::endl;
            break;
        default:
            std::cout << "Padre " << getpid() << std::endl;
            break;
    }
    return 0;
}

