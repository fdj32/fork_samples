#include <chrono>
#include <iostream>
 
int main()
{
    std::cout << "All last days of months of a given year: \n";
 
    constexpr std::chrono::year year{2021};
 
    for (int i{1}; i <= 12; ++i) {
        const std::chrono::month_day_last mdl{std::chrono::month(i) / std::chrono::last};
        const std::chrono::year_month_day_last ymdl{year, mdl};
        std::cout << ymdl << " day: " << ymdl.day() << '\n';
    }
}