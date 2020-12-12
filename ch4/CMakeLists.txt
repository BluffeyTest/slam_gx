## 

cmake_minimum_required(VERSION 3.1)

include_directories("/usr/include/eigen3")

find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

add_executable(useSophus useSophus.cpp)

