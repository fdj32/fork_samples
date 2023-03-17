
 #include <iostream>
#include <string>
#include <utility>

void fa(int i)
{
    if (i == 2)
        return;
    std::cout << "fa("<< i << ")\n";
} // implied return;

int fb(int i)
{
    if (i > 4)
        return 4;
    std::cout << "fb(" << i << ")\n";
    return 2;
}

std::pair<std::string, int> fc(const char* p, int x)
{
    return {p, x};
}

void fd()
{
    return fa(10); // fa(10) is a void expression
}

int main()
{
    fa(1); // prints its argument, then returns
    fa(2); // does nothing when i == 2, just returns

    int i = fb(5); // returns 4
    i = fb(i);     // prints its argument, returns 2
    std::cout << "i = " << i << '\n'
              << "fc(~).second = " << fc("Hello", 7).second << '\n';

    fd();
}
