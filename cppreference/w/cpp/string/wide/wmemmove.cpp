#include <iostream>
#include <cwchar>
#include <locale>
#include <clocale>
 
int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
 
    wchar_t str[] = L"αβγδεζηθικλμνξοπρστυφχψω";
    std::wcout << str << '\n';
    std::wmemmove(str+4, str+3, 3); // copy from [δεζ] to [εζη]
    std::wcout << str << '\n';
}