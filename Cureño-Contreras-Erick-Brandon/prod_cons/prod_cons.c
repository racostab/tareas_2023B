#include <stdio.h>


int main(){
	int error, fd[2], pid, tam = 5;
	char *buf;
	int cnt = 0;
	error = pipe(fd);
	if(error < 0){
		printf("Error\n");
		return 1;
	}
	buf = malloc(sizeof(char)*50);
	pid = fork();
	switch(pid){
		case -1:
			printf("Error\n");
			exit(1);
		case 0:
			read(fd[0], buf, tam);
			printf("H= %s \n", buf);
			break;
		default:
			while(true){
				sleep(4);
				cnt += 1;
				strcpy(buf, "%d", cnt);
				write(fd[1], buf, tam);
				printf("P= %s \n", buf);
			}
			break;
			
	}

	return 0;
}
