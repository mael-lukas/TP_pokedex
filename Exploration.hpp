#ifndef EXPLORATION_HPP
#define EXPLORATION_HPP

#include "State.hpp"

class Exploration : public State {
	public:
	Exploration(Game* game);
	void testBehaviour() override;
};

#endif //EXPLORATION_HPP
