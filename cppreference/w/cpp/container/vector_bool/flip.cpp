
 #include <iostream>
#include <vector>

void print(const std::vector<bool>& vb) {
    for (const bool b : vb)
        std::cout << b;
    std::cout << '\n';
}

int main() {
    std::vector<bool> v{0, 1, 0, 1};
    print(v);
    v.flip();
    print(v);
}
