
 #include <memory>

int main()
{
    auto p = std::make_shared<int>(42);
    std::weak_ptr w{p};    // explicit deduction guide is used in this case
}
