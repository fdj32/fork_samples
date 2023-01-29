#include <iostream>
#include <cctype>
#include <clocale>
 
int main()
{
    unsigned char c = '\xa0'; // the non-breaking space in ISO-8859-1
 
    std::cout << "isprint(\'\\xa0\', default C locale) returned "
               << std::boolalpha << (bool)std::isprint(c) << '\n';
 
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "isprint(\'\\xa0\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::isprint(c) << '\n';
}