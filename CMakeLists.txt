cmake_minimum_required(VERSION 3.17)
project(hashTable)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp source/hashTable.cpp)

add_executable(main main.cpp ${SOURCE_FILES})

target_include_directories(main PRIVATE source)