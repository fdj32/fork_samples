
 #include <iostream>
#include <system_error>
#include <string>

int main()
{
    std::error_condition ec  = std::make_error_condition(std::io_errc::stream);
    std::cout << "error condition for io_errc::stream has value " << ec.value()
              << "\nand message \"" << ec.message() << "\"\n";
}
