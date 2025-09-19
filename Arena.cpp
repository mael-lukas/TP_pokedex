#include "Arena.hpp"
#include <iostream>

Arena::Arena(Game* game) : State(game){}

void Arena::testBehaviour(){
	std::cout << "Arena" << std::endl;
}