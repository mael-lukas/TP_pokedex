#include "../incpp/TitleScreen.hpp"
#include <iostream>

TitleScreen::TitleScreen(Game* game) : State(game) {}

void TitleScreen::testBehaviour() {
    std::cout << "TitleScreen" << std::endl;
    game->changeState(new Exploration(game));
}