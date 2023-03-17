
 #include <iostream>
#include <experimental/random>

int main()
{
    int random_number = std::experimental::randint(100, 999);
    std::cout << "random 3-digit number: " << random_number << '\n';
}
