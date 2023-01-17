#include <iostream>
#include <regex>
#include <string>
 
int main()
{
    std::string target("pattern");
    std::smatch sm;
    std::cout << "default constructed smatch is "
              << (sm.ready() ? " ready\n" : " not ready\n");
 
    std::regex re1("tte");
    std::regex_search(target, sm, re1);
 
    std::cout << "after search, smatch is "
              << (sm.ready() ? " ready\n" : " not ready\n");
}