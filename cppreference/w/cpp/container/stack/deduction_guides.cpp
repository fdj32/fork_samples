
 #include <vector>
#include <stack>
int main() {
   std::vector<int> v = {1,2,3,4};
   std::stack s{v};    // guide #1 deduces std::stack<int, vector<int>>
}
