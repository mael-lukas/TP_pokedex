#ifndef GAME_HPP
#define GAME_HPP

#include "State.hpp"
#include "TitleScreen.hpp"

class Game {
	State* state;

public:
	Game();
	void changeState(State* newState);
	void testBehaviour();
};

#endif //GAME_HPP
