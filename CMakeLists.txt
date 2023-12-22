cmake_minimum_required(VERSION 3.26)
project(Board_Games)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(Board_Games
        include/BoardGame_Classes.hpp
        src/ConnectFour_Board.cpp
        src/GameManager.cpp
        src/Player.cpp
        src/Pyramid_X_O_Board.cpp
        src/RandomPlayer.cpp
        src/X_O_App.cpp
        src/X_O_Board.cpp
        src/X_O_fivegrid_Board.cpp)
