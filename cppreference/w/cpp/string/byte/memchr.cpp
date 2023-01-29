#include <iostream>
#include <cstring>
 
int main()
{
    char arr[] = {'a','\0','a','A','a','a','A','a'};
    char *pc = (char*)std::memchr(arr,'A',sizeof arr);
    if (pc != nullptr)
       std::cout << "search character found\n";
    else
       std::cout << "search character not found\n";
}