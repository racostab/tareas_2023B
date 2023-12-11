#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main() {
    int i = 0;
    pid_t pid;

    do {
        pid = fork();

        if (pid == -1) {
            std::cerr << "El número máximo de procesos es de: " << i << std::endl;
            exit(-1);
        } else if (pid == 0) {
            exit(1);
        } else {
            i++;
        }
    } while (pid);

    return 0;
}
