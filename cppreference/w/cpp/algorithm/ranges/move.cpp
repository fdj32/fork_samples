#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <thread>
#include <chrono>
using namespace std::literals::chrono_literals;
 
void f(std::chrono::milliseconds n)
{
    std::this_thread::sleep_for(n);
    std::cout << "thread with n=" << n.count() << "ms ended" << std::endl;
}
 
int main()
{
#ifndef __clang__
    std::vector<std::jthread> v;
    v.emplace_back(f, 400ms);
    v.emplace_back(f, 600ms);
    v.emplace_back(f, 800ms);
 
    std::list<std::jthread> l;
 
    // std::ranges::copy() would not compile, because std::jthread is non-copyable
    std::ranges::move(v, std::back_inserter(l));
#endif
}