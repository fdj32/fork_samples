#include <iostream>
#include <locale>
#include <list>
 
int main()
{
    std::list<char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a std::list is " << q.max_size() << '\n';
}