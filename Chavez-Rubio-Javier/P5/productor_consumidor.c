/*
    $ gcc -o productor_consumidor productor_consumidor.c
    $ ./productor_consumidor
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int error, fd[2], pid, tam = 5;
    char *buf;
    int cnt = 0;

    error = pipe(fd);
    if (error < 0) {
        printf("Error en la creación del pipe\n");
        return 1;
    }

    buf = (char *)malloc(sizeof(char) * (tam + 1));

    pid = fork();
    switch (pid) {
        case -1:
            printf("Error en la creación del proceso hijo\n");
            exit(1);
        case 0:
            read(fd[0], buf, tam);
            buf[tam] = '\0'; // Asegurar que la cadena termina con '\0'
            printf("Hilo Consumidor: %s\n", buf);
            break;
        default:
            while (1) {
                sleep(1);
                cnt += 1;
                snprintf(buf, tam + 1, "%d", cnt); // Uso de snprintf para formatear la cadena
                write(fd[1], buf, tam);
                printf("Hilo Productor: %s\n", buf);
            }
            break;
    }

    free(buf);
    return 0;
}
