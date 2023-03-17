
 #include <iostream>
#include <string_view>

int main()
{
    using namespace std::literals;

    std::cout
        << std::boolalpha

        // bool starts_with(basic_string_view x) const noexcept;
        << "https://cppreference.com"sv.starts_with("http"sv) << ' ' // true
        << "https://cppreference.com"sv.starts_with("ftp"sv) << ' '  // false

        // bool starts_with(CharT x) const noexcept;
        << "C++20"sv.starts_with('C') << ' ' // true
        << "C++20"sv.starts_with('J') << ' ' // false

        // bool starts_with(const CharT* x) const;
        << std::string_view("string_view").starts_with("string") << ' ' // true
        << std::string_view("string_view").starts_with("String") << ' ' // false
        << '\n';
}
