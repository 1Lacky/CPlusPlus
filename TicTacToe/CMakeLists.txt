cmake_minimum_required(VERSION 3.15)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)
include_directories(./Headers)

add_executable(TicTacToe main.cpp Headers/PlayField.h Headers/TreeNode.h Source/TreeNode.cpp Source/PlayField.cpp)