#include <cstring>
#include <iostream>
#include <iomanip>
 
int main() 
{
    char input[] = "one + two * (three - four)!";
    const char* delimiters = "! +- (*)";
    char *token = std::strtok(input, delimiters);
    while (token) {
        std::cout << std::quoted(token) << ' ';
        token = std::strtok(nullptr, delimiters);
    }
 
    std::cout << "\nContents of the input string now:\n\"";
    for (std::size_t n = 0; n < sizeof input; ++n) {
        if (const char c = input[n]; c != '\0')
            std::cout << c;
        else
            std::cout << "\\0";
    }
    std::cout << "\"\n";
}