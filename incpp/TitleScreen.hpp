#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"

class TitleScreen : public State {
public:
    TitleScreen(Game* game);
    void testBehaviour() override;
};

#endif //TITLESCREEN_HPP
