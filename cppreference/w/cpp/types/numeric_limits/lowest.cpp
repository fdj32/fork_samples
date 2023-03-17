
 #include <iostream>
#include <limits>
#include <string_view>

template<typename T>
void print_twice(std::string_view type, T value)
{
    std::cout << '\t' << type << ": "
              << std::defaultfloat << value << " or "
              << std::hexfloat << value << '\n';
}

int main()
{
    // min()
    std::cout << "std::numeric_limits<T>::min():\n";
    print_twice("float", std::numeric_limits<float>::min());
    print_twice("double", std::numeric_limits<double>::min());
    print_twice("long double", std::numeric_limits<long double>::min());

    // lowest()
    std::cout << "std::numeric_limits<T>::lowest():\n";
    print_twice("float", std::numeric_limits<float>::lowest());
    print_twice("double", std::numeric_limits<double>::lowest());
    print_twice("long double", std::numeric_limits<long double>::lowest());

    // max()
    std::cout << "std::numeric_limits<T>::max():\n";
    print_twice("float", std::numeric_limits<float>::max());
    print_twice("double", std::numeric_limits<double>::max());
    print_twice("long double", std::numeric_limits<long double>::max());
}
