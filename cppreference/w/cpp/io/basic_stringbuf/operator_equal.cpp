// https://en.cppreference.com/w/cpp/io/basic_stringbuf/operator%3D
#include <sstream>
#include <string>
#include <iostream>
 
int main()
{
 
    std::istringstream one("one");
    std::ostringstream two("two");
 
    std::cout << "Before move, one = \"" << one.str() << '"'
              << " two = \"" << two.str() << "\"\n";
 
    *one.rdbuf() = std::move(*two.rdbuf());
 
    std::cout << "After move, one = \"" << one.str() << '"'
              << " two = \"" << two.str() << "\"\n";
}