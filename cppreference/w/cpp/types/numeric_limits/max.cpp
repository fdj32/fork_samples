
 #include <cstddef>
#include <iostream>
#include <limits>
#include <string_view>
#include <type_traits>

template<typename T>
void print_max_twice(std::string_view type)
{
    constexpr T max_value {std::numeric_limits<T>::max()};

    std::cout << type << ": ";
    if constexpr (std::is_floating_point_v<T>)
        std::cout << std::defaultfloat << max_value << " or "
                  << std::hexfloat << max_value << '\n';
    else
        std::cout << std::dec << static_cast<unsigned long long>(max_value) << " or "
                  << std::hex << static_cast<unsigned long long>(max_value) << '\n';
}

int main()
{
    std::cout << std::showbase;

    print_max_twice<bool>("bool");
    print_max_twice<short>("short");
    print_max_twice<int>("int");
    print_max_twice<std::streamsize>("streamsize");
    print_max_twice<std::size_t>("size_t");
    print_max_twice<char>("char");
    print_max_twice<char16_t>("char16_t");
    print_max_twice<wchar_t>("wchar_t");
    print_max_twice<float>("float");
    print_max_twice<double>("double");
    print_max_twice<long double>("long double");
}
