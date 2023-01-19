#include <cassert>
#include <random>
 
int main()
{
    std::mt19937 gen32;
    std::mt19937_64 gen64;
 
    for (auto n{1}; n != 10'000; gen32(), gen64(), ++n);
 
    assert(gen32() == 4'123'659'995);
    assert(gen64() == 9'981'545'732'273'789'042ull);
}