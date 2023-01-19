#include <strstream>
#include <iostream>
 
int main()
{
    {
        std::strstream dyn; // dynamically-allocated read/write buffer
        dyn << "Test: " << 1.23; // note: no std::ends to demonstrate append behavior
        std::cout << "dynamic buffer holds " << dyn.pcount() << " characters: '";
        std::cout.write(dyn.str(), dyn.pcount()) << "'\n";
        // the buffer is now frozen, further output will not make the buffer grow
        dyn << "more output, hopefully enough to run out of the allocated space" << std::ends;
        std::cout << "After more output, it holds "
                  << dyn.pcount() << " characters: '" << dyn.str() << "'\n";
        dyn.freeze(false); // unfreeze before destructor
    } // memory freed by the destructor
 
    {
        char arr[20];
        std::ostrstream st(arr, sizeof arr); // fixed-size buffer
        st << 1.23; // note: no std::ends to demonstrate append behavior
        std::cout << "static buffer holds "
                  << st.pcount() << " characters: '";
        std::cout.write(st.str(), st.pcount());
        std::cout << "'\n";
        st << "more output, hopefully enough to run out of the allocated space" << std::ends;
        std::cout << "static buffer holds "
                  << st.pcount() << " characters: '";
        std::cout.write(st.str(), st.pcount());
        std::cout << "'\n";
    } // nothing to deallocate, no need to unfreeze,
}