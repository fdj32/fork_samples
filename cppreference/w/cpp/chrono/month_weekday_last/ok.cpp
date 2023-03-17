
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto mwdl {std::chrono::March/std::chrono::Wednesday[std::chrono::last]};
    std::cout << (mwdl.ok()) << ' ';
    mwdl = {std::chrono::month(3)/std::chrono::weekday(42)[std::chrono::last]}; 
    std::cout << (mwdl.ok()) << '\n';
}
