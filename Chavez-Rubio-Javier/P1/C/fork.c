#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>

int main(){
    pid_t pid;
    pid = fork();
    switch(pid){
        case -1:
            printf("Error de creación\n");
        break;
        case 0:
            printf("Código del hijo: %d\n", getpid());
        break;
        default:
            printf("Código del padre: %d\n", getpid());
        break;
    }
    return 0;
}