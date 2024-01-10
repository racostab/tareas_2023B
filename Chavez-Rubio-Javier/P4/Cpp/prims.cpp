/*
    $ g++ -o prims prims.cpp -pthread
    $ ./prims
*/

#include <iostream>
#include <thread>
#include <chrono>

void thread_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "Hilo: Terminado después de " << seconds << " segundos.\n";
}

int main() {
    int seconds1 = 3, seconds2 = 5;

    std::thread t1(thread_function, seconds1);
    std::thread t2(thread_function, seconds2);

    t1.join();
    t2.join();

    std::cout << "Programa principal: Todos los hilos han terminado.\n";

    return 0;
}
