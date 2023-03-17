
 #include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::lognormal_distribution<> d(1.6, 0.25);

    std::map<int, int> hist;
    for (int n = 0; n < 1e4; ++n)
        ++hist[std::round(d(gen))];

    for (std::cout << std::fixed << std::setprecision(1); auto [x, y] : hist)
        std::cout << std::hex << x << ' ' << std::string(y / 200, '*') << '\n';
}
