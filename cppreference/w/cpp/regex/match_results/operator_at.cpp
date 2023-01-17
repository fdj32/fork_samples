#include <iostream>
#include <regex>
#include <string>
 
int main()
{
    std::string target("baaaby");
    std::smatch sm;
 
    std::regex re1("a(a)*b");
    std::regex_search(target, sm, re1);
    std::cout << "entire match: " << sm[0] << '\n'
              << "submatch #1: " << sm[1] << '\n';
 
    std::regex re2("a(a*)b");
    std::regex_search(target, sm, re2);
    std::cout << "entire match: " << sm[0] << '\n'
              << "submatch #1: " << sm[1] << '\n';
 
}