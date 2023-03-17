
 #include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>

int main()
{
    std::istringstream str("0.11 0.22 0.33 0.44");

    std::partial_sum(std::istream_iterator<double>(str),
                      std::istream_iterator<double>(),
                      std::ostream_iterator<double>(std::cout, ", "));
}
