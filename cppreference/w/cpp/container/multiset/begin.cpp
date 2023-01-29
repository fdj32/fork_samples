#include <iostream>
#include <iterator>
#include <set>
#include <string>
 
int main()
{
    const std::multiset<std::string> words = {
        "some", "not", "sorted", "words",
        "will", "come", "out", "sorted",
    };
 
    for (auto it = words.begin(); it != words.end(); ) {
        auto cnt = words.count(*it);
        std::cout << *it << ":\t" << cnt << '\n';
        std::advance(it, cnt); // all cnt elements have equivalent keys
    }
}