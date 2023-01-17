#include <filesystem>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
 
std::string to_string(std::filesystem::file_time_type const& ftime) {
    std::time_t cftime = std::chrono::system_clock::to_time_t(
        std::chrono::file_clock::to_sys(ftime));
    std::string str = std::asctime(std::localtime(&cftime));
    str.pop_back();  // rm the trailing '\n' put by `asctime`
    return str;
}
 
int main() {
    auto dir = std::filesystem::current_path();
    using Entry = std::filesystem::directory_entry;
    for (Entry const& entry : std::filesystem::directory_iterator(dir)) {
        std::cout << to_string(entry.last_write_time())
                  << " : " << entry.path().filename() << '\n';
    }
}