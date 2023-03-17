
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
    // matches the a at the end of input
    show_matches("aaa", "a$");

    // matches the o at the end of the first word
    show_matches("moo goo gai pan", "o\\b");

    // the lookahead matches the empty string immediately after the first b
    // this populates m[1] with "aaa" although m[0] is empty
    show_matches("baaabac", "(?=(a+))");

    // because backtracking into lookaheads is prohibited, 
    // this matches aba rather than aaaba
    show_matches("baaabac", "(?=(a+))a*b\\1");

    // logical AND via lookahead: this password matches IF it contains
    // at least one lowercase letter
    // AND at least one uppercase letter
    // AND at least one punctuation character
    // AND be at least 6 characters long
    show_matches("abcdef", "(?=.*[[:lower:]])(?=.*[[:upper:]])(?=.*[[:punct:]]).{6,}");
    show_matches("aB,def", "(?=.*[[:lower:]])(?=.*[[:upper:]])(?=.*[[:punct:]]).{6,}");
}
