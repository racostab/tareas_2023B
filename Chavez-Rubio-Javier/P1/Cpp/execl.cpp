#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main() {
    int ret;
    char *arg1 = "1234567890";
    char *pathname = "hello";

    ret = execl(pathname, pathname, arg1, nullptr);

    return 0;
}
