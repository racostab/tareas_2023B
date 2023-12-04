/*
   Descripción: Proble de productor consumidor con pipes
   Compilación: gcc -o prod_cons_pipes prod_cons_pipes.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int tuberia[2];
void consumidor();
void productor();

int timer_prod, timer_cons;

int main(int argc, char**argv){	
  pid_t pid;
  int error;
    if (argc < 2) {
       timer_prod = 1;
	   timer_cons = 3;
	}else if (argc >= 3 ) {
       timer_prod = atoi(argv[1]);
	   timer_cons = atoi(argv[2]);
	}
    printf("Tiempo de Prod: %d Tiempo de Cons: %d \n", timer_prod, timer_cons);
    error = pipe(tuberia);
    if( error < 0 ){
      printf("Error en la creacion del pipe\n");
      return 1;
    }
    pid = fork();
	switch(pid){
	  case -1:
		       perror("fork");
		       exit(1);
	  case 0:
	           productor();
		       exit(1);
	  default:
	}
    pid = fork();
	switch(pid){
	  case -1:
		       perror("fork");
		       exit(1);
	  case 0:
	           consumidor();
		       exit(1);
	  default: 
	}
	printf("Fin del proceso padre. PID: %d\n", getpid() );
	return 0;
}
void consumidor(){
  int bytes;
  char *buf = calloc(100, sizeof(char));
	printf("\tConsumidor %d\n", getpid() );
    while(1){ 
       sleep(timer_cons);
       bytes = read(tuberia[0], buf, 100);
       printf("\t\t\t%s => C\n", buf);
	   fflush(stdout);
	}
}
void productor(){
  int bytes, tam, cnt;
  char *buf = calloc(100, sizeof(char));
	printf("Productor %d\n", getpid() );
    cnt=1;
    while(1){
	   sprintf(buf, "%d", cnt);
       sleep(timer_prod);
	   tam = strlen(buf);
       write(tuberia[1], buf, tam);
       printf("P => %s\n", buf);
	   fflush(stdout);
       cnt++;
    }
}
