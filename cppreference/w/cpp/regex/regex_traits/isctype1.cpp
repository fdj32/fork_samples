#include <iostream>
#include <string>
#include <regex>
 
int main()
{
    std::regex_traits<char> t;
    std::string str_alnum = "alnum";
    auto a = t.lookup_classname(str_alnum.begin(), str_alnum.end());
    std::string str_w = "w"; // [:w:] is [:alnum:] plus '_'
    auto w = t.lookup_classname(str_w.begin(), str_w.end());
    std::cout << std::boolalpha
              << t.isctype('A', w) << ' ' << t.isctype('A', a) << '\n'
              << t.isctype('_', w) << ' ' << t.isctype('_', a) << '\n'
              << t.isctype(' ', w) << ' ' << t.isctype(' ', a) << '\n';
}