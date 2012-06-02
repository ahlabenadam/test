cmake_minimum_required(VERSION 2.8)
project(Test)
set(Test_VERSION_MAJOR 1)
set(Test_VERSION_MINOR 0)
set(CMAKE_CXX_FLAGS "-g -O0")
set(CMAKE_C_FLAGS   "-g -O0")

configure_file (
	"${PROJECT_SOURCE_DIR}/Test.h.in"
	"${PROJECT_BINARY_DIR}/Test.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(test1 test.cpp)
add_executable(shmget1 shmget1.c)

