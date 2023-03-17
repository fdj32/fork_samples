
 #include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string greeting = "Hello, whirled!";
    std::istringstream iss(greeting);

    std::string hello_comma, whirled, word;

    iss >> hello_comma;
    iss >> whirled;

    std::cout << greeting << '\n'
              << hello_comma << '\n' << whirled << '\n';

    // Reset the stream
    iss.clear();
    iss.seekg(0);

    while (iss >> word)
        std::cout << '+' << word << '\n';
}
