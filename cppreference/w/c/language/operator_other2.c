
 void f(); // no prototype
int main(void)
{
    f(1, 1.0f); // UB unless f is defined to take an int and a double
}
void f(int a, double c) {}
