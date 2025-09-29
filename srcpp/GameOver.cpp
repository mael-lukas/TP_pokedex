#include "../incpp/GameOver.hpp"
#include <iostream>

GameOver::GameOver(Game* game) {this->game = game;}

void GameOver::testBehaviour() {
	std::cout << "GameOver" << std::endl;
}