#include "../incpp/Capture.hpp"
#include <iostream>

Capture::Capture(Game* game) {this->game = game;}

void Capture::testBehaviour() {
	std::cout << "Capture" << std::endl;
	game->changeState(new Exploration(game));

}