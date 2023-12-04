#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

int main() {
    int ret;
    const char *arg1 = "10";
    const char *pathname = "hello";
    std::cout << "proceso" << std::endl;
    ret = execl(pathname, pathname, arg1, nullptr);
    std::cout << "Adios" << std::endl;
    return 0;
}

