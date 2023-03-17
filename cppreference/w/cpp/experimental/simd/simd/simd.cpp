
 #include <experimental/simd>
#include <iostream>
namespace stdx = std::experimental;

int main()
{
    stdx::native_simd<int> a; // uninitialized
    a = 1; // all elements set to 1
    stdx::native_simd<int> b([](int i) { return i; }); // {0, 1, 2, 3, ...}

    alignas(stdx::memory_alignment_v<stdx::native_simd<int>>)
        std::array<int, stdx::native_simd<int>::size() * 2> mem = {};
    for (std::size_t i = 0; i < mem.size(); ++i)
        mem[i] = i & 1;

    stdx::native_simd<int> c(&mem[0], stdx::vector_aligned); // {0, 1, 0, 1, ...}
    stdx::native_simd<int> d(&mem[1], stdx::element_aligned); // {1, 0, 1, 0, ...}

    auto sum = a + b + c + d;

    for (std::size_t i = 0; i < sum.size(); ++i)
        std::cout << sum[i] << ' ';
    std::cout << '\n';
}
