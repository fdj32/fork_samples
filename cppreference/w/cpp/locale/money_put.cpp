
 #include <iostream>
#include <locale>
#include <iomanip>
#include <iterator>

int main()
{
    // using the I/O manipulator
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << "American locale: "
               << std::showbase << std::put_money(12345678.9)<< '\n';

    // using the facet directly
    std::cout.imbue(std::locale("de_DE.UTF-8"));
    std::cout << "German locale: " ;
    auto& f = std::use_facet<std::money_put<char>>(std::cout.getloc());
    f.put({std::cout}, false, std::cout, std::cout.fill(), 12345678.9 );
    std::cout << '\n';
}
