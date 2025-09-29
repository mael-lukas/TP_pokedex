#include "../incpp/Arena.hpp"
#include <iostream>

Arena::Arena(Game* game) {this->game = game;}

void Arena::testBehaviour() {
	std::cout << "Arena" << std::endl;
	game->changeState(new Exploration(game));
}