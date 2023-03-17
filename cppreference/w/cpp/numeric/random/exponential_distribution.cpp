
 #include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <map>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // if particles decay once per second on average,
    // how much time, in seconds, until the next one?
    std::exponential_distribution<> d(1);

    std::map<int, int> hist;
    for (int n = 0; n != 10000; ++n)
        ++hist[2 * d(gen)];

    for (auto const& [x, y] : hist)
        std::cout << std::fixed << std::setprecision(1)
                  << x / 2.0 << '-' << (x + 1) / 2.0 << ' '
                  << std::string(y / 200, '*') << '\n';
}
