
 #include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *name = "PATH";
    const char *env_p = getenv(name);
    if (env_p)
        printf("%s =%s\n", name, env_p);
}
