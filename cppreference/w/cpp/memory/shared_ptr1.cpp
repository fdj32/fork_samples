
 void del(void(*)()) {}

void fun() {}

int main()
{
    std::shared_ptr<void()> ee(fun, del);
    (*ee)();
}
