
 #include <experimental/simd>
#include <cstdint>
#include <iostream>
namespace stdx = std::experimental;

int main()
{
    stdx::native_simd<std::int32_t> a = 1;
    std::cout << a.size() << '\n';
    std::cout << reduce(a) << '\n';
}
