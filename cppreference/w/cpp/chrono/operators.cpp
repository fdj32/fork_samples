#include <iostream>
#include <chrono>
 
int main()
{
    using namespace std::chrono_literals;
 
    std::chrono::seconds halfmin = 30s;
    std::cout << "Half a minute is " << halfmin.count() << " seconds.\n"
        "A minute and a second is " << (1min + 1s).count() << " seconds.\n";
 
    std::chrono::duration moment = 0.1s;
    std::cout << "A moment is " << moment.count() << " seconds.\n"
        "And thrice as much is " << (moment + 0.2s).count() << " seconds.\n";
}