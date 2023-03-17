
 #include <vector>
#include <queue>
int main() {
   std::vector<int> v = {1,2,3,4};
   std::queue s{v};    // guide #1 deduces std::queue<int, vector<int>>
}
