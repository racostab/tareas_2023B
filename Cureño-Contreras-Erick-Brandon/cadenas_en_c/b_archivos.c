/*
	Autor: Cureño Contreras Erick Brandon

    Este programa lee línea por línea del archivo "ejemplo.txt" (.txt) ubicado en la misma dirección.

	Compilación: gcc -o b_archivos b_archivos.c
*/
#include <stdio.h>
int main() {
    // Abrir un archivo en modo lectura
    FILE *archivo = fopen("ejemplo.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer desde el archivo
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        printf("Contenido: %s", buffer);
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}

