
 #include <iostream>
#include <string>
#include <regex>

void show_matches(const std::string& in, const std::string& re)
{
    std::smatch m;
    std::regex_search(in, m, std::regex(re));
    if(!m.empty()) {
        std::cout << "input=[" << in << "], regex=[" << re << "]\n  "
                     "prefix=[" << m.prefix() << "]\n  smatch: ";
        for(std::size_t n = 0; n < m.size(); ++n)
            std::cout << "m[" << n << "]=[" << m[n] << "] ";
        std::cout << "\n  suffix=[" << m.suffix() << "]\n";
    } else {
        std::cout << "input=[" << in << "], regex=[" << re << "]: NO MATCH\n";
    }
}

int main()
{
    show_matches("abcdef", ""); // empty regex is a single empty Alternative
    show_matches("abc", "abc|"); // left Alernative matched first
    show_matches("abc", "|abc"); // left Alernative matched first, leaving abc unmatched
}
