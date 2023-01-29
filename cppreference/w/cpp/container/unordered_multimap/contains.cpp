#include <iostream>
#include <unordered_map>
 
int main()
{
    std::unordered_multimap<int,char> example = {{1,'a'},{2,'b'}};
 
    for(int x: {2, 5}) {
        if(example.contains(x)) {
            std::cout << x << ": Found\n";
        } else {
            std::cout << x << ": Not found\n";
        }
    }
}