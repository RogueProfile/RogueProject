cmake_minimum_required(VERSION 2.6)
project(RogueProject)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
include_directories("src")

add_executable(roguelike ${EXECUTABLE_SOURCES})
target_link_libraries(roguelike SDL2 GL GLEW)

list(APPEND CMAKE_CXX_FLAGS '-std=c++14')
