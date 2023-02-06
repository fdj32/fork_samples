#include <iostream>
#include <cwctype>
#include <locale>
 
int main()
{
    wchar_t c = L'\u0190'; // Latin capital open E ('Ɛ')
 
    std::cout << std::hex << std::showbase;
#ifdef __clang__
    std::cout << "in the default locale, tolower(" << (std::wint_t)c << ") = "
              << (std::wint_t)std::tolower(c, std::locale()) << '\n';
 
    std::cout << "in Unicode locale, tolower(" << (std::wint_t)c << ") = "
              << (std::wint_t)std::tolower(c, std::locale("en_US.utf8")) << '\n';
#endif
}