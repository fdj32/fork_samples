
 #include <random>
#include <iostream>
#include <iterator>
int main()
{
    std::seed_seq s1 = {-1, 0, 1};
    s1.param(std::ostream_iterator<int>(std::cout, " "));
}
