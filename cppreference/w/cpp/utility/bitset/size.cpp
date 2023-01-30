#include <bitset>
#include <iostream>
 
int main() {
    std::cout << std::bitset<0x400>().size() << '\n';
}