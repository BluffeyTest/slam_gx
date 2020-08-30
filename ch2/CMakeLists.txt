# 声明所需要的最低版本
cmake_minimum_required(VERSION 2.8)

# 声明一个工程
project(HelloSLAM)

# 添加可执行程序
# 语法：add_executable(程序名 源代码文件)
add_executable(HelloSLAM hello_slam.cpp)
add_library(hello lib_hell0_slam.cpp)
add_library(hello_shared SHARED lib_hell0_slam.cpp)

add_executable(useHello useHello.cpp)
target_link_libraries(useHello hello_shared )