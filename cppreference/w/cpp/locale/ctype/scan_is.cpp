
 #include <locale>
#include <clocale>
#include <iostream>
#include <iterator>

int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    std::wcout.imbue(std::locale("en_US.utf8"));
    auto& f = std::use_facet<std::ctype<wchar_t>>(std::wcout.getloc());

    // skip until the first letter
    wchar_t s1[] = L"      \t\t\n  Кошка";
    const wchar_t* p1 = f.scan_is(std::ctype_base::alpha, std::begin(s1), std::end(s1));
    std::wcout << "'" << p1 << "'\n";

    // skip until the first letter
    wchar_t s2[] = L"123456789ネプネプ";
    const wchar_t* p2 = f.scan_is(std::ctype_base::alpha, std::begin(s2), std::end(s2));
    std::wcout << "'" << p2 << "'\n";
}
