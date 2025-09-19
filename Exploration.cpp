#include "Exploration.hpp"
#include <iostream>

Exploration::Exploration(Game* game) : State(game){}

void Exploration::testBehaviour(){
	std::cout << "Exploration" << std::endl;
}