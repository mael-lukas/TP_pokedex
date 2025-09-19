#include "GameOver.hpp"
#include <iostream>

GameOver::GameOver(Game* game) : State(game){}

void GameOver::testBehaviour(){
	std::cout << "GameOver" << std::endl;
}