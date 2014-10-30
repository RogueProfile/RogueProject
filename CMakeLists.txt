cmake_minimum_required(VERSION 2.6)
project(RogueProject)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_executable(roguelike ${EXECUTABLE_SOURCES})

list(APPEND CMAKE_CXX_FLAGS '-std=c++14')
