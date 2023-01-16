#include <system_error>
#include <string>
#include <iostream>
 
int main()
{
    auto err = std::make_error_condition(std::errc::invalid_argument);
    std::cout << err.message() << '\n';
}