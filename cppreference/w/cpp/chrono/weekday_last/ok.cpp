
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto wdl {std::chrono::Tuesday[std::chrono::last]};
    std::cout << (wdl.ok()) << ' ';

    wdl = {std::chrono::weekday(42)[std::chrono::last]};
    std::cout << (wdl.ok()) << '\n';
}
