/*
    $ gcc -o threads threads.c -pthread
    $ ./threads
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void* arg);

int main() {
    pthread_t tid1, tid2;
    int status;
    char *texto1 = "hilo 1";
    char *texto2 = "hilo 2";

    status = pthread_create(&tid1, NULL, thread, (void *)texto1);
    if (status < 0) {
        printf("Error en la creacion del Thread 1\n");
        return 1;
    }

    status = pthread_create(&tid2, NULL, thread, (void *)texto2);
    if (status < 0) {
        printf("Error en la creacion del Thread 2\n");
        return 1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    unsigned pid = getpid();
    printf("Tm=%u\n", pid);

    return 0;
}

void* thread(void* arg) {
    char* texto = (char*)arg;
    unsigned tid = (unsigned)pthread_self();
    sleep(10);
    printf("%s: Th=%u\n", texto, tid);
    pthread_exit(NULL);
}
