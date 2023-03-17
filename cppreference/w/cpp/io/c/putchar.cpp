
 #include <cstdio>

int main()
{
    for (char c = 'a'; c != 'z'; c++)
        std::putchar(c);

    // putchar return value is not equal to the argument
    int r = 0x1024;
    std::printf("\nr = 0x%x\n", r);
    r = std::putchar(r);
    std::printf("\nr = 0x%x\n", r);
}
