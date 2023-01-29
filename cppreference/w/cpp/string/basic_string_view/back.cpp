#include <string_view>
#include <iostream>
 
int main() {
    for (std::string_view str{"ABCDEF"}; !str.empty(); str.remove_suffix(1))
        std::cout << str.back() << ' ' << str << '\n';
}