#include <iostream>
#include <system_error>
int main()
{
    std::error_code ec = std::make_error_code(std::io_errc::stream);
 
    // This works because of the overloaded method
    //    and the is_error_code_enum specialization.
    ec = std::io_errc::stream;
 
    std::cout << "Error code from io_errc::stream has category "
              << ec.category().name() << '\n';
}