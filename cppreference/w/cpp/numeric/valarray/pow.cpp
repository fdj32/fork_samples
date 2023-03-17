
 #include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <valarray>

class show
{
    friend std::ostream& operator<< (std::ostream& os, show const& r)
    {
        constexpr char const* sup[]
        {
            "\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074",
            "\u2075", "\u2076", "\u2077", "\u2078", "\u2079",
        };

        for (std::size_t n = 0; n != r.bases.size(); ++n)
        {
            os << std::left << r.bases[n] << std::left;
            if (n < r.exponents.size())
                os << sup[r.exponents[n] % 10] << " ";
            else
                os << "  ";
        }

        if (r.results.size() != 0)
        {
            os << "=";
            for (std::size_t n = 0; n != r.results.size(); ++n)
                os << " " << r.results[n];
        }

        return os << '\n';
    }

public:
    std::valarray<int> bases{}, exponents{}, results{};
};

int main()
{
    constexpr int base { 2 };
    constexpr int exponent { 5 };
    const std::valarray<int> bases { 1, 2, 3, 4, 5, 6, 7 };
    const std::valarray<int> exponents { 0, 1, 2, 3, 4, 5, 6 };
    const std::valarray<int> powers1 = std::pow(bases, exponents);
    const std::valarray<int> powers2 = std::pow(bases, exponent);
    const std::valarray<int> powers3 = std::pow(base, exponents);

    std::cout
        << "pow( const std::valarray<T>& base, const std::valarray<T>& exp ); (1)\n"
        << "base: " << show{bases}
        << "exp : " << show{exponents}
        << "pow : " << show{bases, exponents, powers1}
        << '\n'
        << "pow( const std::valarray<T>& base, const value_type& vexp ); (2)\n"
        << "base: " << show{bases}
        << "vexp: " << exponent << '\n'
        << "pow : " << show{bases, std::valarray<int>(exponent, bases.size()), powers2}
        << '\n'
        << "pow( const value_type& vbase, const std::valarray<T>& exp ); (3)\n"
        << "vbase: " << base << '\n'
        << "exp : " << show{exponents}
        << "pow : " << show{std::valarray<int>(base, bases.size()), exponents, powers3};
}
