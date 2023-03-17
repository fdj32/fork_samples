
 #include <set>
int main() {
   std::set s = {1,2,3,4}; // guide #2 deduces std::set<int>
   std::set s2(s.begin(), s.end()); // guide #1 deduces std::set<int>
}
