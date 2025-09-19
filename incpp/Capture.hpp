#ifndef CAPTURE_HPP
#define CAPTURE_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"

class Capture : public State {
public:
	Capture(Game* game);
	void testBehaviour() override;
};
#endif //CAPTURE_HPP
