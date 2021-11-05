cmake_minimum_required(VERSION 3.00)
project(eightpuzzle CXX)

include_directories(src/include)

add_executable(8puzzle
    src/main.cpp
    src/Output.cpp
    src/Solver.cpp
    src/Board.cpp
    src/SearchNode.cpp
    src/Fringe/Fringe.cpp
    src/Fringe/BFSFringe.cpp
    src/Fringe/DFSFringe.cpp
    src/Fringe/AStarFringe.cpp
    src/FringePolicy/BFSFringePolicy.cpp
    src/FringePolicy/DFSFringePolicy.cpp
    src/FringePolicy/AStarManFringePolicy.cpp
    src/FringePolicy/AStarEucFringePolicy.cpp
    src/FringePolicy/AStarMisplacedFringePolicy.cpp)

target_compile_options(8puzzle
    PRIVATE -Wall
    PRIVATE -Wextra
    PRIVATE -Wpedantic
    PRIVATE -std=c++20)
