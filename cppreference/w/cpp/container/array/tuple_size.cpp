
 #include <iostream>
#include <array>

template<class T>
void test(T)
{
    int a[std::tuple_size<T>::value]; // can be used at compile time
    std::cout << std::size(a) << '\n';
}

int main()
{
    std::array<float, 3> arr;
    test(arr);
}
