#include <algorithm>
#include <iostream>
#include <queue>
 
int main()
{
    std::priority_queue<int> alice;
    std::priority_queue<int> bob;
 
    auto print = [](const auto & title, const auto &cont) { 
        std::cout << title << " size=" << cont.size();
        std::cout << " top=" << cont.top() << '\n';
    };
 
    for (int i = 1; i < 4; ++i)
        alice.push(i);
    for (int i = 7; i < 11; ++i)
        bob.push(i);
 
    // Print state before swap
    print("alice:", alice);
    print("bob  :", bob);
 
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
 
    // Print state after swap
    print("alice:", alice);
    print("bob  :", bob);
}