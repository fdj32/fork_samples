
 #include <numeric>
#include <initializer_list>

int main()
{
    static constexpr auto l = {15, 14};
    static_assert(std::accumulate(l.begin(), l.end(), 13) == 42);
}
