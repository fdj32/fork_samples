
 #include <iostream>
#include <locale>
#include <vector>

int main()
{
    std::vector<char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a std::vector is " << q.max_size() << '\n';
}
