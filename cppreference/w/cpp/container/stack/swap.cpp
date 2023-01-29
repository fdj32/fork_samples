#include <iostream>
#include <stack>
#include <string>
#include <vector>
 
template <typename Stack>
void print(Stack stack /* pass by value */, int id)
{
    std::cout << "s" << id << " [" << stack.size() << "]: ";
    for (; !stack.empty(); stack.pop())
        std::cout << stack.top() << ' ';
    std::cout << (id > 1 ? "\n\n" : "\n");
}
 
int main()
{
    std::vector<std::string>
        v1{"1","2","3","4"},
        v2{"Ɐ","B","Ɔ","D","Ǝ"};
 
    std::stack s1{std::move(v1)};
    std::stack s2{std::move(v2)};
 
    print(s1, 1);
    print(s2, 2);
 
    s1.swap(s2);
 
    print(s1, 1);
    print(s2, 2);
}
