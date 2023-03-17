
 #include <map>
#include <iostream>

int main()
{ 
    std::multimap<int,char> nums {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};

    std::cout << "nums contains " << nums.size() << " elements.\n";
}
