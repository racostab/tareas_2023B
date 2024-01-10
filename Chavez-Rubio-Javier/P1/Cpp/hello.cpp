/*
    $ g++ -o hello hello.cpp
    $ ./hello
*/

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    char *endptr;
    int num = std::strtol(argv[1], &endptr, 10);

    std::cout << "Hello: " << num << std::endl;
    
    return 0;
}
