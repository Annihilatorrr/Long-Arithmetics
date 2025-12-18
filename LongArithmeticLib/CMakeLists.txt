add_library(LongArithmeticLib SHARED
    longarithmetic.h
    longarithmetic.cpp
)

target_include_directories(LongArithmeticLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(LongArithmeticLib PRIVATE LIBRARY_EXPORTS)