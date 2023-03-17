
 #include <iostream>
#include <locale>

// this custom num_put outputs squares of all integers (except long long)
struct squaring_num_put : std::num_put<char>
{
    iter_type do_put(iter_type out, std::ios_base& str,
                     char_type fill, long val) const
    {
        return std::num_put<char>::do_put(out, str, fill, val * val);
    }

    iter_type do_put(iter_type out, std::ios_base& str,
                     char_type fill, unsigned long val) const
    {
        return std::num_put<char>::do_put(out, str, fill, val * val);
    }
};

int main()
{
    auto& facet = std::use_facet<std::num_put<char>>(std::locale());
    facet.put(std::cout, std::cout, '0', 2.71);
    std::cout << '\n';

    std::cout.imbue(std::locale(std::cout.getloc(), new squaring_num_put));
    std::cout << 6 << ' ' << -12 << '\n';
}
