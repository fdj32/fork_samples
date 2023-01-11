#include <assert.h> // no longer needed since C23
int main(void)
{
    // Test if math works.
    static_assert(2 + 2 == 4, "Whoa dude!"); // or _Static_assert(...
 
    // This will produce an error at compile time.
    static_assert(sizeof(int) < sizeof(char),
                 "this program requires that int is less than char");
}