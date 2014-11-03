cmake_minimum_required(VERSION 2.6)
project(RogueProject)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
include_directories("src")

include(FindFreetype)
include_directories(${FREETYPE_INCLUDE_DIR_freetype2})
include_directories(${FREETYPE_INCLUDE_DIR_ft2build})

add_executable(roguelike ${EXECUTABLE_SOURCES})
target_link_libraries(roguelike SDL2 GL GLU GLEW ${FREETYPE_LIBRARY})

list(APPEND CMAKE_CXX_FLAGS '-std=c++14')
