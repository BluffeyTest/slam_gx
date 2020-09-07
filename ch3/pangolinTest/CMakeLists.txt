cmake_minimum_required(VERSION 2.8)
project(generate_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "release")

find_package(Pangolin 0.4 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(generate_test pangolinTest.cpp)
target_link_libraries(generate_test
    ${Pangolin_LIBRARIES}
)
