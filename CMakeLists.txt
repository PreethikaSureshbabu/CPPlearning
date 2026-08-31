# Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# Project name and version
project(CppLearning VERSION 1.0)

# Set C++ standard — use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable warnings — professional practice
if(MSVC)
    add_compile_options(/W4)      # Windows/Visual Studio
else()
    add_compile_options(-Wall -Wextra -Wpedantic)  # GCC/Clang
endif()

# Add subdirectories
add_subdirectory(src/device)
add_subdirectory(src/smartDevice)
add_subdirectory(apps)