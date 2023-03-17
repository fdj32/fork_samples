
 #include <iostream>
#include <regex>

int main()
{
    std::locale::global(std::locale("en_US.utf8"));
    std::regex_traits<char> r1;
    std::regex_traits<wchar_t> r2;
    std::cout << "The regex locale is " << r1.getloc().name() << '\n';
}
