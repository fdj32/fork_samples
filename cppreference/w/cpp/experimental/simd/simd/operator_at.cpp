
 #include <experimental/simd>
#include <iostream>
#include <cstdint>
namespace stdx = std::experimental;

int main()
{
    const stdx::native_simd<std::int64_t> a = 3;
    for (std::size_t i = 0; i != a.size(); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}
