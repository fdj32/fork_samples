
 #include <iostream>
#include <locale>
#include <forward_list>

int main()
{
    std::forward_list<char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a std::forward_list is " << q.max_size() << '\n';
}
