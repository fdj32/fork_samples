
 #include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <array>

int main()
{
    constexpr std::array<std::string_view, 8> data = {"▁","▂","▃","▄","▅","▆","▇","█"};

    std::array<std::string, std::size(data)> arr;

    std::copy(data.cbegin(), data.cend(), arr.begin());
    //             ^              ^           ^

    auto print = [](const std::string_view s) { std::cout << s << ' '; };

    print("Print 'arr' in direct order using [cbegin, cend):\t");
    std::for_each(arr.cbegin(), arr.cend(), print);
    //                ^             ^
    print("\n\nPrint 'arr' in reverse order using [crbegin, crend):\t");
    std::for_each(arr.crbegin(), arr.crend(), print);
    //                ^^             ^^
    print("\n");
}
