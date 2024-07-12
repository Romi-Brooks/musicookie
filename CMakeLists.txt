cmake_minimum_required(VERSION 3.27)
project(musicookie)

set(CMAKE_CXX_STANDARD 20)

add_executable(musicookie src/Musicookie.cpp lib/CoreObjectives/AudioBlockCore.hpp src/CoreObjectives/AudioBlockCore.cpp
        src/ObjectivesFunctions/BasicFunctions.cpp
        lib/ObjectivesFunctions/BasicFunctions.hpp
        src/IOSystem/LogSystem.cpp
        lib/IOSystem/LogSystem.hpp)
