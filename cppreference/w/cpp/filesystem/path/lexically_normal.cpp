
 #include <iostream>
#include <filesystem>
#include <cassert>
namespace fs = std::filesystem;

int main()
{
    assert(fs::path("a/./b/..").lexically_normal() == "a/");
    assert(fs::path("a/.///b/../").lexically_normal() == "a/");
    assert(fs::path("/a/d").lexically_relative("/a/b/c") == "../../d");
    assert(fs::path("/a/b/c").lexically_relative("/a/d") == "../b/c");
    assert(fs::path("a/b/c").lexically_relative("a") == "b/c");
    assert(fs::path("a/b/c").lexically_relative("a/b/c/x/y") == "../..");
    assert(fs::path("a/b/c").lexically_relative("a/b/c") == ".");
    assert(fs::path("a/b").lexically_relative("c/d") == "../../a/b");
    assert(fs::path("a/b").lexically_relative("/a/b") == "");
    assert(fs::path("a/b").lexically_proximate("/a/b") == "a/b");
}
