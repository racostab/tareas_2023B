#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int p = 0;
    pid_t pid;
    std::cout << "PID: " << getpid() << std::endl;

    do {
        pid = fork();
        switch (pid) {
            case -1:
                std::cout << "MAX: " << p << std::endl;
                exit(-1);
                break;
            case 0:
                exit(1);
                break;
            default:
                p++;
                break;
        }
    } while (pid);

    return 0;
}

