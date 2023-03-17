
 #include <cstdio>

int main()
{
    int rc = std::puts("Hello World");

    if (rc == EOF)
        std::perror("puts()"); // POSIX requires that errno is set
}
