
 #include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>

int main() {
    const std::unordered_multiset<std::string> words = {
        "some", "words", "to", "count",
        "count", "these", "words"
    };

    for (auto it = words.begin(); it != words.end(); ) {
        auto cnt = words.count(*it);
        std::cout << *it << ":\t" << cnt << '\n';
        std::advance(it, cnt); // all cnt elements have equivalent keys
    }
}
