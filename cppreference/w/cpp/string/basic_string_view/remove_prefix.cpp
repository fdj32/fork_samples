#include <iostream>
#include <algorithm>
#include <string_view>
int main()
{
    std::string str = "   trim me";
    std::string_view v = str;
    v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));
    std::cout << "String: '" << str << "'\n"
              << "View  : '" << v << "'\n";
}