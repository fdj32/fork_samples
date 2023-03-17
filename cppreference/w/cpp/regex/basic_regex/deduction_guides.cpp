
 #include <regex>
#include <vector>
int main() {
   std::vector<char> v = {'a', 'b', 'c'};
   std::basic_regex re(v.begin(), v.end()); // uses explicit deduction guide
}
