
 #include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <experimental/execution_policy>
#include <experimental/numeric>

int main()
{
    std::vector<double> v(10'000'007, 0.5);

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        double result = std::accumulate(v.begin(), v.end(), 0.0);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::fixed << "std::accumulate result " << result
                  << " took " << ms.count() << " ms\n";
    }

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        double result = std::experimental::parallel::reduce(
                            std::experimental::parallel::par,
                            v.begin(), v.end());
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << "parallel::reduce result "
                  << result << " took " << ms.count() << " ms\n";
    }
}
