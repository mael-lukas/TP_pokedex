#include "Capture.hpp"
#include <iostream>

Capture::Capture(Game* game) : State(game){}

void Capture::testBehaviour(){
	std::cout << "Capture" << std::endl;
}