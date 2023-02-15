cmake_minimum_required(VERSION 3.18.0)
project(LongArithmetics)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include)

add_executable(longarithmetics main.cpp)
add_library(liblongarithmetics SHARED longarithmetic.cpp)
target_link_libraries(longarithmetics liblongarithmetics)
#add_subdirectory(src)
#add_subdirectory(test)