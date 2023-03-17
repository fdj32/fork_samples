
 #include <strstream>
#include <iostream>

int main()
{
    std::ostrstream dyn; // dynamically-allocated output buffer
    dyn << "Test: " << 1.23; // not adding std::ends to demonstrate append behavior
    std::cout << "The output stream holds \"";
    std::cout.write(dyn.str(), dyn.pcount()) << "\"\n"; 
    // the stream is now frozen due to str()
    dyn << " More text" << std::ends;
    std::cout << "The output stream holds \"";
    std::cout.write(dyn.str(), dyn.pcount()) << "\"\n";
    dyn.freeze(false);
}
