
 #include <experimental/simd>
#include <iostream>
#include <algorithm>
namespace stdx = std::experimental;

int main()
{
    [[maybe_unused]]
    stdx::native_simd_mask<int> a;       // uninitialized
    stdx::native_simd_mask<int> b(true); // all elements initialized with true
    stdx::native_simd_mask<int> c{};     // all elements initialized with false

    alignas(stdx::memory_alignment_v<stdx::native_simd_mask<int>>)
        std::array<bool, stdx::native_simd_mask<int>::size() * 2> mem = {};
    std::ranges::generate(mem, [i{0}] mutable -> bool { return i++ & 1; });

    stdx::native_simd_mask<int> d(&mem[0], stdx::vector_aligned);  // {0, 1, 0, 1, ...}
    stdx::native_simd_mask<int> e(&mem[1], stdx::element_aligned); // {1, 0, 1, 0, ...}

    const auto xored = b ^ c ^ d ^ e;

    for (std::size_t i{}; i != xored.size(); ++i)
        std::cout << xored[i] << ' ';
    std::cout << '\n';
}
