#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    int ret;
    char *arg1 = "1234567890";
	char *pathname = "hello";

    ret = execl(pathname, pathname, arg1, NULL);

    return 0;
}  