cmake_minimum_required(VERSION 3.1)
project(binary_search_tree)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")

include_directories("${CMAKE_SOURCE_DIR}/src")

set(SOURCE_FILES src/main.c)
add_executable(binary_search_tree ${SOURCE_FILES} src/binary_search_tree.h src/binary_search_tree.c)

set(TEST_SOURCE_FILES test/test_binary_search_tree.c)
add_executable(test_binary_search_tree ${TEST_SOURCE_FILES} src/binary_search_tree.h src/binary_search_tree.c)

install(TARGETS binary_search_tree
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)

add_custom_target(clean-all
        make clean && rm -fR ${CMAKE_BINARY_DIR}/CMakeCache.txt
        ${CMAKE_BINARY_DIR}/cmake_install.cmake
        ${CMAKE_BINARY_DIR}/Makefile
        ${CMAKE_BINARY_DIR}/CMakeFiles
        && rmdir  ${CMAKE_BINARY_DIR}/out
        )
