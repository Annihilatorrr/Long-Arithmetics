add_executable(LongArithmeticTests
    test_add.cpp
    test_mul.cpp
    test_pow.cpp
    test_factorial.cpp
    test_compare.cpp
    test_sub.cpp
    test_invalid_input.cpp
    test_logger.cpp
)

target_link_libraries(LongArithmeticTests
    gtest
    gtest_main
    LongArithmeticLib
)

target_include_directories(LongArithmeticTests PRIVATE
    ${PROJECT_SOURCE_DIR}/LongArithmeticLib
    ${PROJECT_SOURCE_DIR}/App
)

if(MSVC)
    set_source_files_properties(test_logger.cpp PROPERTIES COMPILE_OPTIONS /Zc:preprocessor)
endif()


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