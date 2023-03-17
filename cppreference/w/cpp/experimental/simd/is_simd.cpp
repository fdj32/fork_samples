
 #include <experimental/simd>
#include <iostream>

namespace stdx = std::experimental;

template <typename T>
void test_simd()
{
    std::cout << std::boolalpha
        << stdx::is_simd_v<T> << ' ' << std::is_constructible_v<T> << '\n';
}

template <typename T>
void test_simd_mask()
{
    std::cout << std::boolalpha
        << stdx::is_simd_mask_v<T> << ' ' << std::is_constructible_v<T> << '\n';
}

int main() 
{
    test_simd<int>();
    test_simd<stdx::simd<float>>();
    test_simd<stdx::simd<bool>>();
    test_simd_mask<int>();
    test_simd_mask<stdx::simd_mask<float>>();
    test_simd_mask<stdx::simd_mask<bool>>();
}
