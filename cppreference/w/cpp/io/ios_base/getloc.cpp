
 #include <iostream>
#include <ctime>
#include <iomanip>
#include <codecvt>

int main()
{
    std::wbuffer_convert<std::codecvt_utf8<wchar_t>> conv(std::cout.rdbuf());
    std::wostream out(&conv);

    out.imbue(std::locale(out.getloc(),
                          new std::time_put_byname<wchar_t>("ja_JP")));

    std::time_t t = std::time(nullptr);
    out << std::put_time(std::localtime(&t), L"%A%c") << '\n';
}
