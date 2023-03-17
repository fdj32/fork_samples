
 #include <iostream>
#include <type_traits>
#include <limits>

template<class T>
typename std::enable_if<std::numeric_limits<T>::is_modulo>::type
    check_overflow()
{
    std::cout << "max value is " << std::numeric_limits<T>::max() << '\n'
              << "min value is " << std::numeric_limits<T>::min() << '\n'
              << "max value + 1 is " << std::numeric_limits<T>::max()+1 << '\n';
}

int main()
{
    check_overflow<int>();
    std::cout << '\n';
    check_overflow<unsigned long>();
//  check_overflow<float>(); // compile-time error, not a modulo type
}
