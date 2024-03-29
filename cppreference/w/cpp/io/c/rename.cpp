
 #include <iostream>
#include <fstream>
#include <cstdio>
int main()
{
    bool ok{std::ofstream("from.txt").put('a')}; // create and write to file
    if (!ok) {
        std::perror("Error creating from.txt");
        return 1;
    }

    if (std::rename("from.txt", "to.txt")) {
        std::perror("Error renaming");
        return 1;
    }

    std::cout << std::ifstream("to.txt").rdbuf() << '\n'; // print file
}
