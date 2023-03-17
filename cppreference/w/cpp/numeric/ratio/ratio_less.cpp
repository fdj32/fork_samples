
 #include <iostream>
#include <ratio>

int main()
{
    if (std::ratio_less<std::ratio<23,37>, std::ratio<57,90>>::value) {
        std::cout << "23/37 < 57/90\n";
    }
}
