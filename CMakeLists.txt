cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Maze_Explorer VERSION 0.1)

# specify C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add executable
add_executable(Maze_Explorer main.cpp)

# link raylib
target_link_libraries(Maze_Explorer raylib)