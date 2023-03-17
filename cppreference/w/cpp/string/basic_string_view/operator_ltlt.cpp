
 #include <iomanip>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::string_view s{"abc"};
    constexpr int width{5};

    // fill/left/right properties are kept until changed
    std::cout << std::setfill('-');
    std::cout << std::left;

    std::cout << '[' << std::setw(width) << s << "]\n";
    std::cout << '[' << std::setw(width) << s << "]\n";

    std::cout << std::right;
    std::cout << '[' << std::setw(width) << s << "]\n";

    // width is reset after each call
    std::cout << '[' << s << "]\n";
}
