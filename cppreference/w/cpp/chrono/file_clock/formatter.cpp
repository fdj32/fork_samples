
 #include <iostream>
#include <format>
#include <chrono>

int main()
{
    std::chrono::time_point<std::chrono::utc_clock> epoch;

    std::cout << std::format("The time of the Unix epoch was {0:%F}T{0:%R%z}.", epoch);
}
