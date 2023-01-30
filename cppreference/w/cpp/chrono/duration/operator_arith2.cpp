#include <chrono>
#include <iostream>
 
int main()
{
    std::chrono::hours h(1);
    std::chrono::minutes m = ++h;
    m--;
    std::cout << m.count() << " minutes\n";
}