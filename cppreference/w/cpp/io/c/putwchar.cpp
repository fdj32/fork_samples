
 #include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <initializer_list>

int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");

    for (const wchar_t ch :{
        L'\u2200', // Unicode name: "FOR ALL"
        L'∀',
        L'\n',
    })
    {
        if (std::putwchar(ch) == WEOF)
        {
            std::puts("I/O error in std::putwchar");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
