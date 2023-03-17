
 #include <optional>

int main()
{
    int a[2];
    std::optional oa{a}; // explicit deduction guide is used in this case
}
