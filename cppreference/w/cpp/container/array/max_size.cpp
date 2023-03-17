
 #include <iostream>
#include <locale>
#include <array>

int main()
{
    std::array<char, 10> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of the std::array is " << q.max_size() << '\n';
}
