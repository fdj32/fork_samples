
 #include <iostream>
#include <deque>

int main()
{
    std::deque<int> c = {1, 2, 3};
    std::cout << "The deque holds: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';

    c.resize(5);
    std::cout << "After resize up to 5: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';

    c.resize(2);
    std::cout << "After resize down to 2: ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';

    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for (const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
}
