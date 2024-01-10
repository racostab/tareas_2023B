/*
    $ gcc -o prims prims.c -pthread
    $ ./prims
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int seconds = *(int*)arg;
    printf("Hilo: Esperando %d segundos...\n", seconds);
    sleep(seconds);
    printf("Hilo: Terminado después de %d segundos.\n", seconds);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;
    int seconds1 = 3, seconds2 = 5;

    pthread_create(&tid1, NULL, thread_function, (void*)&seconds1);
    pthread_create(&tid2, NULL, thread_function, (void*)&seconds2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Programa principal: Todos los hilos han terminado.\n");

    return 0;
}
