/*
	$ gcc -o hello hello.c
	$ ./hello
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	char *endptr;
	int num = strtol(argv[1], &endptr, 10);
	printf("Hello: %d\n",num);
	return 0;
}