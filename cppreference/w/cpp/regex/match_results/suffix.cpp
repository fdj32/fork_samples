
 #include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex re("a(a)*by");
    std::string target("baaaby123");
    std::smatch sm;

    std::regex_search(target, sm, re);
    std::cout << sm.suffix() << '\n';
}
