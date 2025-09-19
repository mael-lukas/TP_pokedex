#ifndef EXPLORATION_HPP
#define EXPLORATION_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Capture.hpp"
#include "Arena.hpp"

class Exploration : public State {
public:
	Exploration(Game* game);
	void testBehaviour() override;
};

#endif //EXPLORATION_HPP
