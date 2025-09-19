cmake_minimum_required(VERSION 3.30)
project(beuzalors)

set(CMAKE_CXX_STANDARD 20)

add_executable(beuzalors srcpp/main.cpp incpp/Pokemon.hpp srcpp/Pokemon.cpp incpp/Pokedex.hpp srcpp/Pokedex.cpp incpp/Pokemon_vector.hpp srcpp/Pokemon_vector.cpp
        incpp/Pokemon_PC.hpp srcpp/Pokemon_PC.cpp incpp/Pokemon_team.hpp srcpp/Pokemon_team.cpp
        srcpp/State.cpp
        incpp/State.hpp
        incpp/Game.hpp
        srcpp/Game.cpp
        incpp/TitleScreen.hpp
        srcpp/TitleScreen.cpp
        srcpp/Exploration.cpp
        incpp/Exploration.hpp
        incpp/Capture.hpp
        srcpp/Capture.cpp
        incpp/Arena.hpp
        srcpp/Arena.cpp
        incpp/GameOver.hpp
        srcpp/GameOver.cpp
)

target_link_libraries(beuzalors
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio)
