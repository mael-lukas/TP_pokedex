#include "../incpp/Arena.hpp"
#include <iostream>

Arena::Arena(Game* game) : State(game) {}

void Arena::testBehaviour() {
	std::cout << "Arena" << std::endl;
	game->changeState(new Exploration(game));
}