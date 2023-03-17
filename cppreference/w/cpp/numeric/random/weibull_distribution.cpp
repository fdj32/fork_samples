
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

    std::weibull_distribution<> d;

    std::map<int, int> hist;
    for (int n = 0; n != 10000; ++n)
        ++hist[std::round(d(gen))];

    std::cout << std::fixed << std::setprecision(1) << std::hex;
    for (auto [x, y]: hist)
        std::cout << x << ' ' << std::string(y / 200, '*') << '\n';
}
