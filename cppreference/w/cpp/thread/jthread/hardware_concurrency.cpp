#include <iostream>
#include <thread>
 
int main() {
    unsigned int n = std::jthread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
}