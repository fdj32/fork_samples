
 #include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    // Pat goes door-to-door selling cookies
    // At each house, there's a 75% chance that she sells one box
    // how many times will she be turned away before selling 5 boxes?
    std::negative_binomial_distribution<> d(5, 0.75);

    std::map<int, int> hist;
    for (int n = 0; n != 10000; ++n)
        ++hist[d(gen)];

    for (auto [x, y] : hist)
        std::cout << std::hex << x << ' ' << std::string(y / 100, '*') << '\n';
}
