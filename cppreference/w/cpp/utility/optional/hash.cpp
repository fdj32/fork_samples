
 #include <optional>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std::literals;
int main()
{
    using OptStr = std::optional<std::string>;

    // hash<optional> makes it possible to use unordered_set
    std::unordered_set<OptStr> s = {
        "ABC"s, "abc"s, std::nullopt, "def"s
    };

    for(const auto& o : s) {
        std::cout << o.value_or("(null)") << '\t' << std::hash<OptStr>{}(o) << '\n';
    }
}
