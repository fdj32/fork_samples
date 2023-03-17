
 #include <algorithm>
#include <iostream>
#include <string_view>

using namespace std::literals;

[[nodiscard("a pure function")]]
constexpr std::size_t count_substrings(std::string_view hive, std::string_view const bee)
{
    if (hive.empty() or bee.empty())
        return 0U;

    std::size_t buzz{};
    while (bee.size() <= hive.size())
    {
        const auto pos = hive.find(bee);
        if (pos == hive.npos)
            break;
        ++buzz;
        hive.remove_prefix(pos + bee.size());
    }
    return buzz;
}

int main()
{
    std::string str = "   trim me";
    std::string_view v = str;
    v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));
    std::cout << "String: '" << str << "'\n"
              << "View : '" << v << "'\n";

    constexpr auto hive {"bee buzz bee buzz bee"};
    std::cout << "There are " << count_substrings(hive, "bee") << " bees in this hive.\n";
}
