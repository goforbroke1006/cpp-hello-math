cmake_minimum_required(VERSION 3.17)
project(cpp-hello-math)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
        main.cpp
        Matrix.h
        Vector.h
        operations.h
        linear-transformation.h)