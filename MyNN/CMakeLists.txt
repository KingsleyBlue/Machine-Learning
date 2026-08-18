cmake_minimum_required(VERSION 3.15)

project(MyNN)

set(CMAKE_CXX_STANDARD 17)


find_package(Matrix REQUIRED)


add_executable(main
    example/main.cpp
    src/Perceptron.cpp
)


target_include_directories(main PRIVATE
    include
)


target_link_libraries(main PRIVATE
    Matrix::Matrix
)