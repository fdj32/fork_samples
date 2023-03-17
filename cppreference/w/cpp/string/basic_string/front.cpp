
 #include <iostream>
#include <string>

int main()
{
    std::string s("Exemplary");
    char& f1 = s.front();
    f1 = 'e';
    std::cout << s << '\n'; // "exemplary"

    std::string const c("Exemplary");
    char const& f2 = c.front();
    std::cout << &f2 << '\n'; // "Exemplary"
}
