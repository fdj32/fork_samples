
 #include <random>
#include <iostream>
int main()
{
    std::seed_seq s1 = {-1, 0, 1};
    std::cout << s1.size() << '\n';
}
