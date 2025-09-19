#ifndef GAME_HPP
#define GAME_HPP

#include "State.hpp"

class Game {
	State* state;

	public:
    	Game();
    	~Game();
        void changeState(State* state);
        void testBehaviour();
};

#endif //GAME_HPP
