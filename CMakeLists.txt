cmake_minimum_required(VERSION 3.28)
project(musicookie_new)

set(CMAKE_CXX_STANDARD 20)

add_executable(musicookie_new musicookie.cpp
        CoreObject/Mixer.cpp
        CoreObject/Mixer.hpp)
