
 #include <functional>
int func(double) { return 0; }
int main() {
  std::function f{func}; // guide #1 deduces function<int(double)>
  int i = 5;
  std::function g = [&](double) { return i; }; // guide #2 deduces function<int(double)>
}
