
 #include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex re("a(a)*b");
    std::string target("aaab");
    std::smatch sm;

    std::regex_match(target, sm, re);
    std::cout << sm.position(1) << '\n';
}
