
 #include <iostream>
#include <ratio>

int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;

    using diff = std::ratio_subtract<two_third, one_sixth>;
    std::cout << "2/3 - 1/6 = " << diff::num << '/' << diff::den << '\n';
}
