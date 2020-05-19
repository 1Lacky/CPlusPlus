cmake_minimum_required(VERSION 3.15)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)
include_directories(./Headers)

add_executable(Matrix main.cpp Headers/Matrix3x3.h Source/Matrix3x3.cpp Headers/MatrixXnX.h Source/MatrixXnX.cpp Headers/LinkedList.h Source/LinkedList.cpp)