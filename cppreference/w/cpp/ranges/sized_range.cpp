
 #include <ranges>
#include <list>
#include <forward_list>

int main()
{
    static_assert(std::ranges::sized_range<std::list<int>>
          and not std::ranges::sized_range<std::forward_list<int>>);
}
