set(TARGET_NAME monkeypp)
add_library(${TARGET_NAME} lexer.cpp)
target_include_directories(${TARGET_NAME} PUBLIC .)
target_link_libraries(${TARGET_NAME} PUBLIC magic_enum)
