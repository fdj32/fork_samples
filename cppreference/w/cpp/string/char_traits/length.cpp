
 #include <iostream>
#include <iomanip>
#include <string>

void print(const char* str)
{
    std::cout << std::quoted(str) << " has length = "
              << std::char_traits<char>::length(str) << '\n';
}

int main()
{
    print("foo");

    std::string s{"booo"};
    print(s.c_str());
}
