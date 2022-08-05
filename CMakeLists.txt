cmake_minimum_required(VERSION 3.16)
project(SFML_Simon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SFML_Simon main.cpp button.cpp game.cpp)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(SFML_Simon sfml-window sfml-system sfml-audio sfml-network sfml-graphics)