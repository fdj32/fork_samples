#include <stack>
#include <deque>
#include <iostream>
 
int main()
{
    std::stack<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';
 
    std::stack<int> c2(c1);
    std::cout << c2.size() << '\n';
 
    std::deque<int> deq {3, 1, 4, 1, 5};
    std::stack<int> c3(deq); // overload (2)
    std::cout << c3.size() << '\n';
 
#   ifdef __cpp_lib_adaptor_iterator_pair_constructor
    const auto il = {2, 7, 1, 8, 2};
    std::stack<int> c4 { il.begin(), il.end() }; // overload (6), C++23
    std::cout << c4.size() << '\n';
#   endif
}