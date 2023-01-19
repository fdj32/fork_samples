#include <iostream>
#include <sstream>
 
int main()
{
    std::stringstream stream("Hello, world");
    std::cout << "sgetc() returned '" << (char)stream.rdbuf()->sgetc() << "'\n";
    std::cout << "peek() returned '" << (char)stream.peek() << "'\n";
    std::cout << "get() returned '" << (char)stream.get() << "'\n";
}