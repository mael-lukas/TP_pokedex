#ifndef CAPTURE_HPP
#define CAPTURE_HPP

#include "State.hpp"

class Capture : public State {
	public:
	Capture(Game* game);
	void testBehaviour() override;
};

#endif //CAPTURE_HPP
