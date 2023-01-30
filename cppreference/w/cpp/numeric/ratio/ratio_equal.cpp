#include <iostream>
#include <ratio>
 
int main()
{
    constexpr bool equ = std::ratio_equal_v<std::ratio<2,3>,
                                            std::ratio<4,6>>;
 
    std::cout << "2/3 " << (equ ? "==" : "!=") << " 4/6\n";
}