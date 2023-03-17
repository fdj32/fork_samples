
 #include <experimental/optional>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std::literals;
int main()
{
    // hash<optional> makes it possible to use unordered_set
    std::unordered_set<std::experimental::optional<std::string>> s = {
            "abc"s, std::experimental::nullopt, "def"s
    };

    for(const auto& o : s)
        std::cout << o.value_or("(null)") << ' ';
}
