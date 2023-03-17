
 #include <expected>
#include <iostream>
#include <string_view>

enum class parse_error {
    invalid_char,
    overflow
};

std::expected<double, parse_error>
parse_number(std::string_view& str) {
    const char* begin = str.data();
    char* end;
    double retval = std::strtod(begin, &end);

    if (begin == end) {
        return std::unexpected(parse_error::invalid_char);
    }
    // else if (retval == std::numeric_limits<double>::infinity) {
    //     return std::unexpected(parse_error::overflow);
    // }

    str.remove_prefix(end - begin);
    return retval;
}

auto main(void) -> int {

    std::string_view src = "12";
    // change the src to "meow" or something invalid
    // that is can not be converted to a number and observe the output
    auto num = parse_number(src);

    if (num.has_value()) {
        // if num does not have a value
        // dereferencing num will cause an undefined behaviour
        std::cout << *num << "\n";
        // num.value():     throws std::bad_expected_access
        // num.value_or(0): uses specified default value
    }
    else if (num.error() == parse_error::invalid_char) {
        // handle ...
    }
    else if (num.error() == parse_error::overflow) {
        // handle ...
    }
    else {
        // do another thing
    }

    return EXIT_SUCCESS;
}
