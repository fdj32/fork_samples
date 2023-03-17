
 #include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> vec = {3, 1, 4};
    if (std::ranges::find(vec, 5) != std::ranges::cend(vec))
        std::cout << "Found a 5 in vector vec!\n";

    int arr[] = {5, 10, 15};
    if (std::ranges::find(arr, 5) != std::ranges::cend(arr))
        std::cout << "Found a 5 in array arr!\n";
}
