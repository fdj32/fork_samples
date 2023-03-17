
 #include <experimental/simd>
#include <iostream>
namespace stdx = std::experimental;

int main()
{
    alignas(stdx::memory_alignment_v<stdx::native_simd<int>>)
        std::array<int, stdx::native_simd<int>::size()> mem = {};

    stdx::native_simd<int> a = 7;
    a.copy_to(&mem[0], stdx::vector_aligned);

    for (int e : mem)
        std::cout << e << ' ';
    std::cout << '\n';
}
