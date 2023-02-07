#include <sstream>
#include <iostream>
 
int main()
{
    std::istringstream s1;
    s1 = std::istringstream("test"); // OK
 
    //std::cin = std::istringstream("test"); // ERROR: 'operator=' is protected
}