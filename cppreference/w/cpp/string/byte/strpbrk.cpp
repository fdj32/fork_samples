
 #include <iostream>
#include <cstring>
#include <iomanip>

int main()
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";

    unsigned int cnt = 0;
    do {
       str = std::strpbrk(str, sep); // find separator
       std::cout << std::quoted(str) << '\n';
       if(str) str += std::strspn(str, sep); // skip separator
       ++cnt; // increment word count
    } while(str && *str);

    std::cout << "There are " << cnt << " words\n";
}
