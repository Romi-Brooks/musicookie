cmake_minimum_required(VERSION 3.28)
project(musicookie_new)

set(CMAKE_CXX_STANDARD 20)

add_executable(musicookie_new musicookie.cpp
        CoreObject/Mixer/Mixer.cpp
        CoreObject/Mixer/Mixer.hpp
        IOSystem/Log/Log.cpp
        IOSystem/Log/Log.hpp)
