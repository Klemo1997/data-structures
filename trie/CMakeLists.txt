cmake_minimum_required(VERSION 3.1)
project(trie)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")

include_directories("${CMAKE_SOURCE_DIR}/src")

set(SOURCE_FILES src/main.c)
add_executable(trie ${SOURCE_FILES} src/trie.h src/trie.c src/array_list/array_list.h src/array_list/array_list.c)

set(TEST_SOURCE_FILES test/test_trie.c)
add_executable(test_trie ${TEST_SOURCE_FILES} src/trie.h src/trie.c src/array_list/array_list.h src/array_list/array_list.c)

set(TEST_SOURCE_FILES test/test_array_list.c)
add_executable(test_array_list ${TEST_SOURCE_FILES} src/array_list/array_list.h src/array_list/array_list.c)

install(TARGETS trie
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)

add_custom_target(clean-all
        make clean && rm -fR ${CMAKE_BINARY_DIR}/CMakeCache.txt
        ${CMAKE_BINARY_DIR}/cmake_install.cmake
        ${CMAKE_BINARY_DIR}/Makefile
        ${CMAKE_BINARY_DIR}/CMakeFiles
        && rmdir  ${CMAKE_BINARY_DIR}/out
        )
