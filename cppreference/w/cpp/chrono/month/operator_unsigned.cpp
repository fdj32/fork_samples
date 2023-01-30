#include <iostream>
#include <chrono>
 
int main()
{
    constexpr std::chrono::month m {6};
    constexpr unsigned p = static_cast<unsigned>(m);
    constexpr unsigned q = static_cast<unsigned>(std::chrono::September);
    std::cout << "The month is: " << p << '\n'
              << "September is: " << q << '\n'; 
}