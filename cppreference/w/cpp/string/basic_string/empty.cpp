#include <iostream>
#include <string>
 
int main()
{
    std::string s;
    std::boolalpha(std::cout);
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
 
    s = "Exemplar";
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
 
    s = "";
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
}