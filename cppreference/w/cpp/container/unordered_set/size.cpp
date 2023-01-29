#include <unordered_set>
#include <iostream>
 
int main()
{ 
    std::unordered_set<int> nums {1, 3, 5, 7};
 
    std::cout << "nums contains " << nums.size() << " elements.\n";
}