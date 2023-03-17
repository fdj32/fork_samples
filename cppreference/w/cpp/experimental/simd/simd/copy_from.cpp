
 #include <experimental/simd>
#include <iostream>
#include <numeric>
namespace stdx = std::experimental;

void print(auto const& a)
{
    for (std::size_t i{}; i != std::size(a); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

int main()
{
    alignas(stdx::memory_alignment_v<stdx::native_simd<int>>)
        std::array<int, stdx::native_simd<int>::size() * 2> mem = {};
    std::iota(mem.begin(), mem.end(), 0);
    print(mem);

    stdx::native_simd<int> a; // uninitialized

    a.copy_from(&mem[0], stdx::vector_aligned);
    print(a);

    a.copy_from(&mem[1], stdx::element_aligned); // vector_aligned would likely crash
    print(a);
}
