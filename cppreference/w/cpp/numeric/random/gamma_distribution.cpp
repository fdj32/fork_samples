
 #include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // A gamma distribution with alpha=1, and beta=2
    // approximates an exponential distribution.
    std::gamma_distribution<> d(1,2);

    std::map<int, int> hist;
    for (int n = 0; n != 10000; ++n)
        ++hist[2*d(gen)];

    for (auto const& [x, y] : hist)
        if (y / 100. > 0.5)
            std::cout
                << std::fixed << std::setprecision(1)
                << x / 2.0 << '-' << (x + 1) / 2.0 << ' '
                << std::string(y / 100, '*') << '\n';
}
