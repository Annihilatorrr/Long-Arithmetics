add_executable(LongArithmeticTests
    tests_main.cpp
    test_add.cpp
    test_mul.cpp
    test_pow.cpp
    test_compare.cpp
    test_sub_positive.cpp
)

target_link_libraries(LongArithmeticTests
    gtest
    gtest_main
    LongArithmeticLib
)

target_include_directories(LongArithmeticTests PRIVATE
    ${PROJECT_SOURCE_DIR}/LongArithmeticLib
)


add_custom_command(TARGET LongArithmeticTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "INFO Copying $<TARGET_FILE:LongArithmeticLib> -> $<TARGET_FILE_DIR:LongArithmeticTests>"
)

add_custom_command(TARGET LongArithmeticTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:LongArithmeticLib>
        $<TARGET_FILE_DIR:LongArithmeticTests>
)

include(GoogleTest)
gtest_discover_tests(LongArithmeticTests)