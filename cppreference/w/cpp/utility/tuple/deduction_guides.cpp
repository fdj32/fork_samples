
 #include <tuple>
int main()
{
    int a[2], b[3], c[4];
    std::tuple t1{a, b, c}; // explicit deduction guide is used in this case
}
