set(TARGET_NAME test)
add_executable(${TARGET_NAME} test.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE monkeypp catch2)
