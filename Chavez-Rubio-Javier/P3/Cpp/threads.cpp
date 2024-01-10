/*
	g++ -o threads threads.cpp -std=c++11 -pthread
	./threads
*/
#include <iostream>
#include <thread>

void thread_function() {
    std::thread::id thread_id = std::this_thread::get_id();
    std::cout << "ID del hilo: " << thread_id << std::endl;
}

int main() {
    std::thread t(thread_function);
    t.join();

    return 0;
}