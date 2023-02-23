
```
**********************************************************************
** Visual Studio 2019 Developer Command Prompt v16.11.22
** Copyright (c) 2021 Microsoft Corporation
**********************************************************************

C:\Program Files (x86)\Microsoft Visual Studio\2019\Community>code C:\Users\nfeng\hub\fdj32\fork_samples\cppreference

C:\Program Files (x86)\Microsoft Visual Studio\2019\Community>

code C:\Users\nfeng\hub\fdj32\fork_samples\cppreference

make -i -j 9

```

```

sudo apt install libboost-all-dev

g++ -std=c++20 w/cpp/memory/uninitialized_default_construct_n.cpp -o build/./w/cpp/memory/uninitialized_default_construct_n.cpp.exe


#ifndef __clang__


export C_INCLUDE_PATH=$C_INCLUDE_PATH:/opt/homebrew/include
export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/opt/homebrew/include
export LIBRARY_PATH=$LIBRARY_PATH:/opt/homebrew/lib


find build/ -name *.exe | grep -v dSYM | wc -l

find build/ -name *.exe | wc -l

find w -name *.c -or -name *.cpp | wc -l

find w -name *.c -or -name *.cpp | grep -v '()' | grep -v '*' | awk '{print "add_executable("$1".exe "$1")"}' > CMakeLists.txt


cmake_minimum_required(VERSION 3.25)
project(cppreference)
if(POLICY CMP0037)
  cmake_policy(SET CMP0037 OLD)
endif()
set(CMAKE_C_FLAGS " -std=c2x ")
set(CMAKE_CXX_FLAGS " -std=c++2b -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors -g ")
set(CMAKE_EXE_LINKER_FLAGS " -lm -lpthread ")

```

```
-- Configuring done
CMake Error at CMakeLists.txt:1809 (add_executable):
  Cannot find source file:

    (

  Tried extensions .c .C .c++ .cc .cpp .cxx .cu .mpp .m .M .mm .ixx .cppm .h
  .hh .h++ .hm .hpp .hxx .in .txx .f .F .for .f77 .f90 .f95 .f03 .hip .ispc


CMake Error at CMakeLists.txt:1809 (add_executable):
  No SOURCES given to target: w/cpp/utility/functional/function/operator


CMake Error at CMakeLists.txt:1814 (add_executable):
  No SOURCES given to target:
  w/cpp/utility/functional/reference_wrapper/operator


CMake Error at CMakeLists.txt:1833 (add_executable):
  No SOURCES given to target:
  w/cpp/utility/functional/move_only_function/operator


CMake Error at CMakeLists.txt:1899 (add_executable):
  No SOURCES given to target: w/cpp/utility/hash/operator


CMake Generate step failed.  Build files cannot be regenerated correctly.
nfeng@utmubuntu:~/logs/cppreference$ ^C
nfeng@utmubuntu:~/logs/cppreference$ grep 'w/cpp/utility/functional/function/operator' CMakeLists.txt 
add_executable(w/cpp/utility/functional/function/operator_cmp.cpp.exe w/cpp/utility/functional/function/operator_cmp.cpp)
add_executable(w/cpp/utility/functional/function/operator().cpp.exe w/cpp/utility/functional/function/operator().cpp)
add_executable(w/cpp/utility/functional/function/operator_bool.cpp.exe w/cpp/utility/functional/function/operator_bool.cpp)
nfeng@utmubuntu:~/logs/cppreference$ 
nfeng@utmubuntu:~/logs/cppreference$ 
nfeng@utmubuntu:~/logs/cppreference$ 
nfeng@utmubuntu:~/logs/cppreference$ 
nfeng@utmubuntu:~/logs/cppreference$ grep '()' CMakeLists.txt 
add_executable(w/cpp/utility/functional/function/operator().cpp.exe w/cpp/utility/functional/function/operator().cpp)
add_executable(w/cpp/utility/functional/reference_wrapper/operator().cpp.exe w/cpp/utility/functional/reference_wrapper/operator().cpp)
add_executable(w/cpp/utility/functional/move_only_function/operator().cpp.exe w/cpp/utility/functional/move_only_function/operator().cpp)
add_executable(w/cpp/utility/hash/operator().cpp.exe w/cpp/utility/hash/operator().cpp)
nfeng@utmubuntu:~/logs/cppreference$ 
```