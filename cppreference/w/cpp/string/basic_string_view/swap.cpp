
 #include <string_view>
#include <iostream>

int main() {
    auto s1{ std::string_view{"⏺⏺⏺⏺⏺"} };
    auto s2{ std::string_view{"⏹⏹⏹⏹⏹"} };

    std::cout << "Before: " << s1 << ' ' << s2 << "\n";
    s1.swap(s2);
    std::cout << "After : " << s1 << ' ' << s2 << "\n";
}
