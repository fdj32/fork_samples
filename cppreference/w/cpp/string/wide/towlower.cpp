
 #include <iostream>
#include <cwctype>
#include <clocale>

int main()
{
    wchar_t c = L'\u0190'; // Latin capital open E ('Ɛ')

    std::cout << std::hex << std::showbase;
    std::cout << "in the default locale, towlower(" << (std::wint_t)c << ") = "
              << std::towlower(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, towlower(" << (std::wint_t)c << ") = "
              << std::towlower(c) << '\n';
}
