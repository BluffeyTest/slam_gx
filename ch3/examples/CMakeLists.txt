cmake_minimum_required(VERSION 2.8)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "-std=c++11" )


project(geometry)

find_package(Pangolin 0.4 REQUIRED)

include_directories("/usr/include/eigen3")

include_directories(${Pangolin_INCLUDE_DIRS})

#add_executable(eigenExample coordinateTransform.cpp)

#add_executable(plotTraje plotTrajectory.cpp)
add_executable(geometry plotTrajectory.cpp)

target_link_libraries(geometry  ${Pangolin_LIBRARIES})




