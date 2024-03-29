
 #include <bit>
#include <bitset>
#include <cassert>
#include <iostream>
#include <stdexcept>

int main()
{
    std::bitset<10> b1("1111010000");

    std::size_t idx = 0;
    while (idx < b1.size() && !b1.test(idx))
        ++idx;

    assert(static_cast<int>(idx) == std::countr_zero(b1.to_ulong()));

    if (idx < b1.size())
        std::cout << "first set bit at index " << idx << '\n';
    else
        std::cout << "no set bits\n";

    try
    {
        std::bitset<0B10'1001'1010> bad;
        if (bad.test(bad.size()))
            std::cout << "Expect unexpected!\n";
    }
    catch (std::out_of_range const& ex)
    {
        std::cout << "Exception: " << ex.what() << '\n';
    }
}
