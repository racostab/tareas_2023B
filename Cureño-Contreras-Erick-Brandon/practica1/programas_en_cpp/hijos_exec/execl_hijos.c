#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	char *endptr;
	int numero = strtol(argv[1], &endptr, 10);
	int numero1 = strtol(argv[2], &endptr, 10);
	int numero2 = strtol(argv[3], &endptr, 10);
	//printf("Hello: %d, %d\n",numero, numero1);
	
	
	int j, k;
	//printf("Proceso %d imprimiendo, esperando: %d\n", getpid(), forkf);
	for(j = numero; j < numero1; j++){
		for(k = 0; k < numero2; k++){
			printf("\t");
		}
		printf("%d: \n", j);
	}
	sleep(2);
	
	return 0;
}
