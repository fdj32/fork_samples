
 #include <iostream>
#include <string_view>
#include <experimental/source_location>

void log(const std::string_view message,
         const std::experimental::source_location location =
               std::experimental::source_location::current())
{
    std::cout << "info:"
              << location.file_name() << ":"
              << location.line() << " "
              << message << '\n';
}

int main()
{
    log("Hello world!");
}
