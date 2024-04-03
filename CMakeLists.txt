cmake_minimum_required(VERSION 3.27)
project(musicookie)

set(CMAKE_CXX_STANDARD 20)

add_executable(musicookie src/Musicookie.cpp src/lib/CoreObjective/AudioBlockCore.hpp src/CoreObjectives/AudioBlockCore.cpp)
