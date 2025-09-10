cmake_minimum_required(VERSION 3.30)
project(beuzalors)

set(CMAKE_CXX_STANDARD 20)

add_executable(beuzalors main.cpp Pokemon.hpp Pokemon.cpp Pokedex.hpp Pokedex.cpp Pokemon_vector.hpp Pokemon_vector.cpp Pokemon_party.hpp Pokemon_party.cpp)

target_link_libraries(beuzalors
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio)
