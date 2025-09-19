#ifndef ARENA_HPP
#define ARENA_HPP

#include "State.hpp"

class Arena : public State{
	public:
	Arena(Game* game);
	void testBehaviour() override;
};



#endif //ARENA_HPP
