#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    char *endptr;
    int numero = std::strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        std::cerr << "Error: No es un número válido." << std::endl;
        return 1;
    }

    std::cout << "Hello: " << numero << std::endl;
    return 0;
}

