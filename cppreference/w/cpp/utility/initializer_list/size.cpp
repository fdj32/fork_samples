
 #include <initializer_list>
int main() { static_assert(std::initializer_list{1,2,3,4}.size() == 4); }
