
 #include <experimental/iterator>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> x{1, 2, 3, 4};
    std::copy(x.begin(), x.end(),
              std::experimental::make_ostream_joiner(std::cout, ", "));
}
