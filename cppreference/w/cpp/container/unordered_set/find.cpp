#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#ifndef __clang__
#include <source_location>
#endif
#include <unordered_set>
 
using namespace std::literals;
 
namespace logger { bool enabled{false}; }
#ifndef __clang__
inline void who(const std::source_location sloc = std::source_location::current())
{
    if (logger::enabled) std::cout << sloc.function_name() << '\n';
}
#endif
struct string_hash // C++20's transparent hashing
{
    using hash_type = std::hash<std::string_view>;
    using is_transparent = void;
#ifndef __clang__
    std::size_t operator()(const char* str) const        { who(); return hash_type{}(str); }
    std::size_t operator()(std::string_view str) const   { who(); return hash_type{}(str); }
    std::size_t operator()(std::string const& str) const { who(); return hash_type{}(str); }
#endif
};
 
int main()
{
    std::unordered_set<int> example = { 1, 2, -10 };
#ifndef __clang__
    std::cout << "Simple comparison demo:\n" << std::boolalpha;
    if (auto search = example.find(2); search != example.end())
        std::cout << "Found " << *search << '\n';
    else
        std::cout << "Not found\n";
 
    std::unordered_set<std::string, string_hash, std::equal_to<>> set{"one"s, "two"s};
 
    logger::enabled = true;
    std::cout << "Heterogeneous lookup for unordered containers (transparent hashing):\n"
              << (set.find("one")   != set.end()) << '\n'
              << (set.find("one"s)  != set.end()) << '\n'
              << (set.find("one"sv) != set.end()) << '\n';
#endif
}