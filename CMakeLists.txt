cmake_minimum_required(VERSION 3.25.0)
project(CppPrimer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("./includes/")

add_executable(CppPrimer "./src/chaper11/p421.cpp")
