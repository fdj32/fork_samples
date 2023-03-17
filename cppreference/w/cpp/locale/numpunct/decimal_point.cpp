
 #include <iostream>
#include <locale>

struct slash : std::numpunct<char> {
    char do_decimal_point()   const { return '/'; }  // separate with slash
};

int main()
{
    std::cout.precision(10);
    std::cout << "default locale: " << 1234.5678 << '\n';
    std::cout.imbue(std::locale(std::cout.getloc(), new slash));
    std::cout << "locale with modified numpunct: " << 1234.5678 << '\n';
}
