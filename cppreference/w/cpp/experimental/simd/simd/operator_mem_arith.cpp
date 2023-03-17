
 #include <experimental/simd>
#include <iostream>
namespace stdx = std::experimental;

int main()
{
    const stdx::native_simd<int> a = 0;
    for (std::size_t i = 0; i < sum.size(); ++i) {
        ++a;
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
