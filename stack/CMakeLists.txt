cmake_minimum_required(VERSION 3.1)
project(stack)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")

include_directories("${CMAKE_SOURCE_DIR}/src")

set(SOURCE_FILES src/main.c)
add_executable(stack ${SOURCE_FILES} src/stack.h src/stack.c)

set(TEST_SOURCE_FILES test/test_stack.c)
add_executable(test_stack ${TEST_SOURCE_FILES} src/stack.h src/stack.c)

install(TARGETS stack
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)

add_custom_target(clean-all
        make clean && rm -fR ${CMAKE_BINARY_DIR}/CMakeCache.txt
        ${CMAKE_BINARY_DIR}/cmake_install.cmake
        ${CMAKE_BINARY_DIR}/Makefile
        ${CMAKE_BINARY_DIR}/CMakeFiles
        && rmdir  ${CMAKE_BINARY_DIR}/out
        )
