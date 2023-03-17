
 #include <iostream>
#include <string_view>
int main()
{
    std::string str = "Exemplar";
    std::string_view v = str;
    std::cout << v[2] << '\n';
//  v[2] = 'y'; // Error: cannot modify through a string view
    str[2] = 'y';
    std::cout << v[2] << '\n';
}
