
 #include <chrono>
#include <iostream>
#include <format>

using namespace std::literals;
int main()
{
    std::chrono::hh_mm_ss c{16h + 32min + 10s};

    std::cout << "%R: " << std::format("{:%R}", c) << '\n'
              << "%T: " << std::format("{:%T}", c) << '\n';
}
