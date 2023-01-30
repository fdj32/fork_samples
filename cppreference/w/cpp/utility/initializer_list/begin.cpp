#include <initializer_list>
 
int main()
{
    static constexpr auto il = {42, 24};
    static_assert(*il.begin() == 0x2A);
}