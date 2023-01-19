#include <iostream>
#include <iomanip>
 
int main ()
{
  std::cout << "With default setting : [" << std::setw(10) << 40 << "]\n";
  char prev = std::cout.fill('x');
  std::cout << "Replaced '" << prev << "' with '"
            << std::cout.fill() << "': [" << std::setw(10) << 40 << "]\n";
}