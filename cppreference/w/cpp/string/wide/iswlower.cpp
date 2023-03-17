
 #include <iostream>
#include <cwctype>
#include <clocale>

int main()
{
    wchar_t c = L'\u0444'; // Cyrillic small letter ef ('ф')

    std::cout << std::hex << std::showbase << std::boolalpha;
    std::cout << "in the default locale, iswlower(" << (std::wint_t)c << ") = "
              << (bool)std::iswlower(c) << '\n';
    std::setlocale(LC_ALL, "en_US.utf8");
    std::cout << "in Unicode locale, iswlower(" << (std::wint_t)c << ") = "
              << (bool)std::iswlower(c) << '\n';
}
