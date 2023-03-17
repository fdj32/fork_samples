
 #include <iostream>
#include <functional>

void call(std::function<int()> f)  // can be passed by value
{ 
    std::cout << f() << '\n';
}

int normal_function() 
{
    return 42;
}

int main()
{
    int n = 1;
    std::function<int()> f = [&n](){ return n; };
    call(f);

    n = 2;
    call(f); 

    f = normal_function; 
    call(f);
}
