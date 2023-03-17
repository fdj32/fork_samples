
 #include <experimental/simd>
#include <iostream>
namespace stdx = std::experimental;

void print(const stdx::native_simd_mask<int> x) {
    for (std::size_t i = 0; i < x.size(); ++i) {
        std::cout << std::boolalpha << x[i] << ' ';
    }
    std::cout << std::endl;
}

void print(const stdx::native_simd<int> x) {
    for (std::size_t i = 0; i < x.size(); ++i) {
        std::cout << x[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    const stdx::native_simd<int> a([](int i) { return i; });
    print(!a);
    print(~a);
    print(+a);
    print(-a);
    return 0;
}
