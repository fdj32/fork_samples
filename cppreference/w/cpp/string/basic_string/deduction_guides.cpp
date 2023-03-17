
 #include <string>
#include <vector>
int main() {
   std::vector<char> v = {'a', 'b', 'c'};
   std::basic_string s(v.begin(), v.end()); // uses explicit deduction guide
}
