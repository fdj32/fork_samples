
 #include <iostream>
#include <chrono>

int main()
{
    for (const unsigned u : {0, 1, 6, 7, 8, 9}) {
        const std::chrono::weekday wd{u};
        std::cout 
            << "u = " << u << ", wd = "
            << wd.c_encoding() // Monday is 1
            << (wd.ok() ? " is a valid weekday.\n"
                        : " is an invalid weekday!\n");
    }
}
