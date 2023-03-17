
 #include <stdio.h>

int main(void)
{
    int rc = fputs("Hello World", stdout);

    if (rc == EOF)
       perror("fputs()"); // POSIX requires that errno is set
}
