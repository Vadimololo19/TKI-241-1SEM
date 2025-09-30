cmake_minimum_required(VERSION 3.14)
project(MatrixSolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(MatrixLib
    MatrixLib/Matrix.h
    MatrixLib/Generator.h
    MatrixLib/RandomGenerator.h
    MatrixLib/IStreamGenerator.h
    MatrixLib/Exercise.h
    MatrixLib/Task1Exercise.h
    MatrixLib/Task1Exercise.cpp
    MatrixLib/Task2Exercise.h
    MatrixLib/Task2Exercise.cpp
    MatrixLib/Task3Exercise.h
    MatrixLib/Task3Exercise.cpp
)

target_include_directories(MatrixLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)

add_executable(ConsoleApp ConsoleApp/main.cpp)
target_link_libraries(ConsoleApp PRIVATE MatrixLib)

add_subdirectory(Tests)
