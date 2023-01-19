#include <sstream>
#include <iostream>
 
int main()
{
    std::istringstream s1("Hello, world.");
    char c1 = s1.get();
    if (s1.unget())
    {
        char c2 = s1.get();
        std::cout << "Got: " << c1 << " got again: " << c2 << '\n';
    }
}