cmake_minimum_required(VERSION 3.21)
project(TikTAKToe)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(TikTAKToe
        Game.cpp
        Game.hpp
        main.cpp
        player.cpp
        player.hpp)
