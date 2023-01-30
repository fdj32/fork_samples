#include <iostream>
#include <typeindex>
int main() {
    std::cout << std::type_index(typeid(std::cout)).name();
}