#include <iostream>
#include <limits>
#include <locale>
 
struct space_out : std::numpunct<char>
{
    char do_thousands_sep()   const { return ' ';  } // separate with spaces
    std::string do_grouping() const { return "\1"; } // groups of 1 digit
};
 
struct g123 : std::numpunct<char>
{
    std::string do_grouping() const { return "\1\2\3"; }
};
 
int main()
{
    std::cout << "default locale: " << 12345678 << '\n';
    std::cout.imbue(std::locale(std::cout.getloc(), new space_out));
    std::cout << "locale with modified numpunct: " << 12345678 << '\n';
    std::cout.imbue(std::locale(std::cout.getloc(), new g123));
    std::cout << "Locale with \\1\\2\\3 grouping: " << 
              std::numeric_limits<unsigned long long>::max() << '\n';
}