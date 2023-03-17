
 #include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

int main()
{
    std::string s("Exemparl");
    std::next_permutation(s.begin(), s.end());

    std::string c;
    std::copy(s.cbegin(), s.cend(), std::back_inserter(c));
    std::cout << c <<'\n'; // "Exemplar"
}
