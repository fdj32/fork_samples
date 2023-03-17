
 #include <ranges>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>

int main()
{
    static_assert(
            std::ranges::bidirectional_range<std::set<int>> and
        not std::ranges::bidirectional_range<std::unordered_set<int>> and
            std::ranges::bidirectional_range<std::list<int>> and
        not std::ranges::bidirectional_range<std::forward_list<int>>
    );
}
