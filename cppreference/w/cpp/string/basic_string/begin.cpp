
 #include <string>
#include <iostream>

int main()
{
    std::string s("Exemplar");
    *s.begin() = 'e';
    std::cout << s <<'\n';

    auto i = s.cbegin();
    std::cout << *i << '\n';
//  *i = 'E'; // error: i is a constant iterator
}
