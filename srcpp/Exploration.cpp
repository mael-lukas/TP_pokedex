#include "../incpp/Exploration.hpp"
#include <iostream>

Exploration::Exploration(Game* game) : State(game) {}

void Exploration::testBehaviour() {
	std::cout << "Exploration" << std::endl;
	if (rand() % 2 == 1) {
		game->changeState(new Capture(game));
	}
	else {
		game->changeState(new Arena(game));
	}
}