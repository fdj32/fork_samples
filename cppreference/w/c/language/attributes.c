
 [[gnu::always_inline]] [[gnu::hot]] [[gnu::const]] [[nodiscard]]
int f(void); // declare f with four attributes

[[gnu::always_inline, gnu::const, gnu::hot, nodiscard]]
int f(void); // same as above, but uses a single attr specifier that contains four attributes

int f(void) { return 0; }

int main(void)
{
}
