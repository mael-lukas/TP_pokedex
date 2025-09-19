cmake_minimum_required(VERSION 3.30)
project(beuzalors)

set(CMAKE_CXX_STANDARD 20)

add_executable(beuzalors main.cpp Pokemon.hpp Pokemon.cpp Pokedex.hpp Pokedex.cpp Pokemon_vector.hpp Pokemon_vector.cpp
        Pokemon_PC.hpp Pokemon_PC.cpp Pokemon_team.hpp Pokemon_team.cpp TitleScreen.hpp TitleScreen.cpp State.hpp State.cpp Game.hpp Game.cpp
        Arena.cpp
        Arena.hpp
        Exploration.cpp
        Exploration.hpp
        Capture.cpp
        Capture.hpp
        GameOver.cpp
        GameOver.hpp)

target_link_libraries(beuzalors
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio)
