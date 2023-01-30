#include <iostream>
#include <string_view>
#include <source_location>
 
inline void cur_line(
    const std::string_view message = "",
    const std::source_location& location = std::source_location::current())
{
    std::cout
        << location.line() // <- the line # of a call site
        << ") "
        << message; 
}
 
int main()
{
    cur_line("++\n");
    cur_line(); std::cout << "Hello,\n";
    cur_line(); std::cout << "C++20!\n";
    cur_line("--\n");
}