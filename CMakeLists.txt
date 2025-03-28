cmake_minimum_required(VERSION 3.28)
project(musicookie)

set(CMAKE_CXX_STANDARD 20)

add_executable(musicookie musicookie.cpp
        CoreObject/Mixer/Mixer.cpp
        CoreObject/Mixer/Mixer.hpp
        IOSystem/Log/Log.cpp
        IOSystem/Log/Log.hpp
        CoreObject/Block/Block.cpp
        CoreObject/Block/Block.hpp
        CoreObject/Chain/BlockFX/BlockFX.cpp
        CoreObject/Chain/BlockFX/BlockFX.hpp)
