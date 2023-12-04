/*
	Autor: Cureño Contreras Erick Brandon
    Este programa lee carácter por carácter del archivo "ejemplo.txt" (.txt) ubicado en la misma dirección.
	Compilación: gcc -o archivos archivos.c
*/
#include <stdio.h>

int main() {
    FILE *archivo = fopen("ejemplo.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int caracter;

    // Leer caracteres uno por uno hasta llegar al final del archivo (EOF)
    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}

