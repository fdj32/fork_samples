#include <iostream>
#include <locale>
 
void try_with(wchar_t c, const char* loc)
{
    #ifndef __clang__
    std::wcout << "isblank('" << c << "', locale(\"" << loc << "\")) returned " << std::boolalpha
               << std::isblank(c, std::locale(loc)) << '\n';
    #endif    
}
int main()
{
    const wchar_t IDEO_SPACE = L'\u3000'; // Unicode character 'IDEOGRAPHIC SPACE'
    try_with(IDEO_SPACE, "C");
    try_with(IDEO_SPACE, "en_US.UTF-8");
}