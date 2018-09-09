cmake_minimum_required(VERSION 3.10)
project(ctoy)

set(CMAKE_CXX_STANDARD 11)

add_executable(ctoy main.cpp leetcode/utils/utils.h leetcode/utils/utils.cpp leetcode/p11.cpp leetcode/p1_15_18.cpp)