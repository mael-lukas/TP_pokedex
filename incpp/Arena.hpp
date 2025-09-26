#ifndef ARENA_HPP
#define ARENA_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"

class Arena : public State {
public:
	Arena(Game* game);
	void testBehaviour();
};

#endif //ARENA_HPP
