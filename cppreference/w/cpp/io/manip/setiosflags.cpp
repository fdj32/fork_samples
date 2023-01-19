#include <iostream>
#include <iomanip>
 
int main()
{
    std::cout << std::resetiosflags(std::ios_base::dec) 
              << std::setiosflags(  std::ios_base::hex
                                  | std::ios_base::uppercase
                                  | std::ios_base::showbase) << 42 << '\n';
}