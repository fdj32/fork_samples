
 #include <ranges>
#include <vector>
#include <array>
#include <deque>
#include <valarray>
#include <list>
#include <set>

template<typename T> concept CR = std::ranges::contiguous_range<T>;

int main()
{
    int a[4];
    static_assert(
            CR<std::vector<int>> and
        not CR<std::vector<bool>> and
        not CR<std::deque<int>> and
            CR<std::valarray<int>> and
            CR<decltype(a)> and
        not CR<std::list<int>> and
        not CR<std::set<int>> and
            CR<std::array<std::list<int>,42>>
    );
}
