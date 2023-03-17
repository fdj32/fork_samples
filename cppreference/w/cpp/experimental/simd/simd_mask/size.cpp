
 #include <experimental/simd>
#include <iostream>
namespace stdx = std::experimental;

int main()
{
    stdx::native_simd_mask<int> a = true;
    std::cout << a.size() << '\n';
    std::cout << popcount(a) << '\n';
    return 0;
}
