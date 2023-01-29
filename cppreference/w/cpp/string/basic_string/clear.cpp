#include <cassert>
#include <string>
 
int main()
{
    std::string s{ "Exemplar" };
    std::string::size_type const capacity = s.capacity();
 
    s.clear();
    assert(s.capacity() == capacity); // <- not guaranteed
    assert(s.empty());
    assert(s.size() == 0);
}