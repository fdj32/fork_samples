#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymwdi {1/std::chrono::Wednesday[1]/2021};
    ymwdi = std::chrono::years(5) + ymwdi;
    // First Wednesday in January, 2026
    std::cout << (static_cast<std::chrono::year_month_day>(ymwdi) == 
                  std::chrono::January/7/2026) << ' ';
    ymwdi = ymwdi - std::chrono::months(6);
    // First Wednesday in July, 2025
    std::cout << (static_cast<std::chrono::year_month_day>(ymwdi) ==
                  std::chrono::July/2/2025) << '\n';
}