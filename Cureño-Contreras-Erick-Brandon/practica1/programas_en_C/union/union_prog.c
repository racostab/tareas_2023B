#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
	int i;
	int valores[] = {0, 12,18,30};
	pid_t proceso, rfork, sfork;
	printf("Padre: %d\n",getpid());
	for (i = 0; i < 3; i++){
		rfork = fork();
		switch(rfork){
			case -1:
				printf("Error\n");
			break;
			case 0:
				funcion(sfork, valores[i], valores[i+1], i);
				exit(1);
			break;
			default:
				waitpid(rfork, NULL, 0);
				sfork = rfork;
			break;
		}
	}
	waitpid(rfork);
	printf("Fin\n");
	return 0;
}

void funcion(pid_t forkf, int m, int mm, int t){
	char arg1[10];
	snprintf(arg1, sizeof(arg1), "%d", m);
	char arg2[10];
	snprintf(arg2, sizeof(arg2), "%d", mm);
	char arg3[10];
	snprintf(arg3, sizeof(arg3), "%d", t);
	execl("execl_hijos", "execl_hijos", arg1, arg2, arg3, NULL);
}
