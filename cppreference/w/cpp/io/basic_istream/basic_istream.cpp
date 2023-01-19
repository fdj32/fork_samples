#include <sstream>
#include <iostream>
 
int main()
{
    std::istringstream s1("hello");
    std::istream s2(s1.rdbuf());                        // OK: s2 shares the buffer with s1
 
//    std::istream s3(std::istringstream("test"));      // ERROR: move constructor is protected
//    std::istream s4(s2);                              // ERROR: copy constructor is deleted
    std::istringstream s5(std::istringstream("world")); // OK: move ctor called by derived class
 
    std::cout << s2.rdbuf() << ' ' << s5.rdbuf() << '\n';
}