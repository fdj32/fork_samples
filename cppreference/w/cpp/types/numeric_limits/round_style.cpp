
 #include <iostream>
#include <limits>

auto print(std::float_round_style frs)
{
    switch (frs)
    {
        case std::round_indeterminate:
            return "Rounding style cannot be determined";
        case std::round_toward_zero:
            return "Rounding toward zero";
        case std::round_to_nearest:
            return "Rounding toward nearest representable value";
        case std::round_toward_infinity:
            return "Rounding toward positive infinity";
        case std::round_toward_neg_infinity:
            return "Rounding toward negative infinity";
    }
    return "unknown round style";
}

int main()
{
    std::cout << std::hexfloat
              << "The decimal 0.1 is stored in a double as "
              << 0.1 << '\n'
              << "The decimal 0.3 is stored in a double as "
              << 0.3 << '\n'
              << print(std::numeric_limits<double>::round_style) << '\n';
}
