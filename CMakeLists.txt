cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Maze_Explorer VERSION 0.1)

# specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# for clang
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add executable
add_executable(Maze_Explorer main.cpp)

# link raylib
target_link_libraries(Maze_Explorer raylib)