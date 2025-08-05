set(APP_NAME laapp)
set(LIB_NAME LongArithmeticLib)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} PRIVATE ${LIB_NAME})

target_include_directories(${APP_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/${LIB_NAME})

add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "INFO Copying $<TARGET_FILE:${LIB_NAME}> -> $<TARGET_FILE_DIR:${APP_NAME}>"
)

add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${LIB_NAME}>
        $<TARGET_FILE_DIR:${APP_NAME}>
)
