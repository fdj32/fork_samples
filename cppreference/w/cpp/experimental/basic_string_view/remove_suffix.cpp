
 #include <iostream>
#include <experimental/string_view>
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', '\0', '\0', '\0'};
    std::experimental::string_view v(arr, sizeof arr);
    auto trim_pos = v.find('\0');
    if(trim_pos != v.npos)
        v.remove_suffix(v.size() - trim_pos);
    std::cout << "Array: '" << arr << "', size=" << sizeof arr << '\n'
              << "View: '" << v << "', size=" << v.size() << '\n';
}
