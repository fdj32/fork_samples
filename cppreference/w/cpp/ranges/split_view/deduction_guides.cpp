
 #include <ranges>
#include <string_view>
#include <type_traits>
using std::operator""sv;

int main() {
    std::ranges::split_view w1{"a::b::c"sv, "::"sv};
    static_assert(std::is_same_v<
        decltype(w1),
        std::ranges::split_view<std::string_view, std::string_view>>);

    std::ranges::split_view w2{"x,y,z"sv, ','};
    static_assert(std::is_same_v<
        decltype(w2),
        std::ranges::split_view<std::string_view, std::ranges::single_view<char>>>);
}
