
 #include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
    std::istringstream one("one");
    std::ostringstream two("two");

    std::cout << "Before swap, one = " << std::quoted( one.str() )
              <<  " two = " << quoted( two.str() ) << '\n';

    one.rdbuf()->swap(*two.rdbuf());

    std::cout << "After  swap, one = " << quoted( one.str() )
              << " two = " << quoted( two.str() ) << '\n';
}
