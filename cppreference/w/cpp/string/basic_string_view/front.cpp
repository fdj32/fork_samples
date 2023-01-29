#include <string_view>
#include <iostream>
 
int main() {
    for (std::string_view str{"ABCDEF"}; !str.empty(); str.remove_prefix(1))
        std::cout << str.front() << ' ' << str << '\n';
}