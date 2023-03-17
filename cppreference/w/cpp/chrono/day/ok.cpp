
 #include <iostream>
#include <chrono>

int main()
{
    std::chrono::day d1{15};
    std::cout << static_cast<unsigned>(d1);
    if (d1.ok()) {
        std::cout << " is a valid day.\n";
    } else {
        std::cout << " is an invalid day!\n";
    }

    std::chrono::day d2{35};
    std::cout << static_cast<unsigned>(d2)
              << (d2.ok() ? " is a valid day.\n"
                          : " is an invalid day!\n");
}
