#include <iostream>
#include <utility>
 
int main()
{
    auto p1 = std::make_pair(10, 3.14);
    auto p2 = std::pair(12, 1.23); // CTAD, since C++17
 
    auto print_p1_p2 = [&](auto msg) {
        std::cout << msg
                  << "p1 = {" << std::get<0>(p1)
                  << ", "     << std::get<1>(p1) << "}, "
                  << "p2 = {" << std::get<0>(p2)
                  << ", "     << std::get<1>(p2) << "}\n";
    };
 
    print_p1_p2("Before p1.swap(p2): ");
    p1.swap(p2);
    print_p1_p2("After  p1.swap(p2): ");
    std::swap(p1, p2);
    print_p1_p2("After swap(p1, p2): ");
}