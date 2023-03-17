
 #include <experimental/simd>
#include <iostream>
namespace stdx = std::experimental;

int main()
{
    const stdx::native_simd_mask<int> a = true;
    for (std::size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
