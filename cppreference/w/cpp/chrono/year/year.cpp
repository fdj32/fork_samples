
 #include <chrono>
#include <iostream>

int main() {
    using namespace std::chrono;

    constexpr int leap_years = [] {
        int count{};
        for (int i{year::min()}; i <= int{year::max()}; ++i)
            if (year{i}.is_leap()) // uses constructor (2)
                ++count;
        return count;
    } ();

    static_assert(15891 == leap_years);

    std::cout << "There are " << leap_years << " leap years in the range ["
              << int(year::min()) << ", " << int(year::max()) << "].\n";
}
