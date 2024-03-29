
 #include <algorithm>
#include <iostream>
#include <map>

int main()
{
    std::map<int, char> alice{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    std::map<int, char> bob{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};

    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };

    // Print state before swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';

    std::cout << "-- SWAP\n";
    std::swap(alice, bob);

    // Print state after swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
}
