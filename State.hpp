#ifndef STATE_HPP
#define STATE_HPP

#include "Game.hpp"

class State {
  	protected:
		Game* game;
		State(Game* game);

   	public:
        virtual ~State() = default;
        virtual void testBehaviour() = 0;
};

#endif //STATE_HPP
