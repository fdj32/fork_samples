
 #include <iostream>
#include <string>

int main()
{
    std::string s("Exemplary");
    char& back1 = s.back();
    back1 = 's';
    std::cout << s << '\n'; // "Exemplars"

    std::string const c("Exemplary");
    char const& back2 = c.back();
    std::cout << back2 << '\n'; // 'y'
}
