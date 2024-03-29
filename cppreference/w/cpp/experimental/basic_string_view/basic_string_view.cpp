
 #include <iostream>
#include <experimental/string_view>
int main()
{
    std::string cppstr = "Foo";
    char array[3] = {'B', 'a', 'r'};

    std::experimental::string_view cppstr_v(cppstr);
    std::experimental::string_view array_v(array, sizeof array);

    std::experimental::wstring_view wcstr_v = L"xyzzy";

    std::cout << cppstr_v << '\n'
              << array_v << '\n'
              << wcstr_v.size() << '\n';
}
