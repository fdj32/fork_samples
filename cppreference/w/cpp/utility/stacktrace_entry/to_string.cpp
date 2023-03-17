
 #include <stacktrace>
#include <string>
#include <iostream>

int main()
{
    auto st = std::stacktrace::current();
    std::cout <<
        "Description of an empty stacktrace entry:\n" +
        std::to_string(std::stacktrace_entry{}) << '\n';
    if (st.size() > 0) {
        std::cout <<
            "Description of a non-empty stacktrace entry:\n" +
            std::to_string(st[0]) << '\n';
    }
}
