
 #include <locale>
#include <iostream>

int main()
{
    std::cout << "The non-converting char<->char codecvt::always_noconv() returns " 
              << std::boolalpha
              << std::use_facet<std::codecvt<char, char, std::mbstate_t>>(
                    std::locale()
                 ).always_noconv() << "\n"
              << "while wchar_t<->char codecvt::always_noconv() returns "
              << std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(
                    std::locale()
                 ).always_noconv() << "\n";

}
