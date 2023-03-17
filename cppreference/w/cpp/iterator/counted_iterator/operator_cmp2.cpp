
 #include <initializer_list>
#include <iterator>

int main()
{
    static constexpr auto v = {1, 2, 3, 4};
    constexpr std::counted_iterator<std::initializer_list<int>::iterator>
        it1 {v.begin(), 3},
        it2 {v.begin(), 0};
    static_assert( it1 != std::default_sentinel );
    static_assert( it2 == std::default_sentinel );
    static_assert( std::default_sentinel != it1 );
    static_assert( std::default_sentinel == it2 );
}
