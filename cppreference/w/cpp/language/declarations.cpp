
 #include <type_traits>

struct S {
    int member;
    // decl-specifier-seq is "int"
    // declarator is "member"

} obj, *pObj(&obj);
// decl-specifier-seq is "struct S { int member; }"
// declarator "obj" declares an object of type S
// declarator "*pObj" declares a pointer to S,
//     and initializer "(&obj)" initializes it

int i = 1, *p = nullptr, f(), (*pf)(double);
// decl-specifier-seq is "int"
// declarator "i" declares a variable of type int,
//     and initializer "= 1" initializes it
// declarator "*p" declares a variable of type int*,
//     and initializer "= nullptr" initializes it
// declarator "f()" declares (but doesn't define)
//     a function taking no arguments and returning int
// declarator "(*pf)(double)" declares a pointer to function
//     taking double and returning int

int (*(*var1)(double))[3] = nullptr;
// decl-specifier-seq is "int"
// declarator is "(*(*var1)(double))[3]"
// initializer is "= nullptr"

// 1. declarator "(*(*var1)(double))[3]" is an array declarator:
//    Type declared is: "(*(*var1)(double))" array of 3 elements
// 2. declarator "(*(*var1)(double))" is a pointer declarator:
//    Type declared is: "(*var1)(double)" pointer to array of 3 elements
// 3. declarator "(*var1)(double)" is a function declarator:
//    Type declared is: "(*var1)" function taking "(double)",
//    returning pointer to array of 3 elements.
// 4. declarator "(*var1)" is a pointer declarator:
//    Type declared is: "var1" pointer to function taking "(double)",
//    returning pointer to array of 3 elements.
// 5. declarator "var1" is an identifier.
// This declaration declares the object var1 of type "pointer to function
// taking double and returning pointer to array of 3 elements of type int"
// The initializer "= nullptr" provides the initial value of this pointer.

// C++11 alternative syntax:
auto (*var2)(double) -> int (*)[3] = nullptr;
// decl-specifier-seq is "auto"
// declarator is "(*var2)(double) -> int (*)[3]"
// initializer is "= nullptr"

// 1. declarator "(*var2)(double) -> int (*)[3]" is a function declarator:
//    Type declared is: "(*var2)" function taking "(double)", returning "int (*)[3]"
// ...

int main()
{
    static_assert(std::is_same_v<decltype(var1), decltype(var2)>);
}
