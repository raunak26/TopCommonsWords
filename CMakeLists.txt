cmake_minimum_required(VERSION 3.13)
project(TopCommonWords)

set(CMAKE_CXX_STANDARD 11)

add_executable(TopCommonWords main.cpp StringFunctions.cpp StringFunctions.h wordCount.cpp wordCount.h)
target_compile_options(TopCommonWords PRIVATE -Wall -Werror)