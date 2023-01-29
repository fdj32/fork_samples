#include <iostream>
#include <locale>
#include <deque>
 
int main()
{
    std::deque<char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a std::deque is " << q.max_size() << '\n';
}