# CMake minimum required version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(simlyte VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(simlyte main.c character/esper.c character/characters.c battle-utils/turns.c)
