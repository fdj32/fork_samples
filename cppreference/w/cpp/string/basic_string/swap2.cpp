#include <string>
#include <iostream>
 
int main() 
{
    std::string a = "AAAA";
    std::string b = "BBB";
 
    std::cout << "before swap" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
 
    std::swap(a,b);
 
    std::cout << "after swap" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}