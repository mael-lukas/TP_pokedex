#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include "State.hpp"

class TitleScreen : public State {
  	public:
	TitleScreen(Game* game);
    void testBehaviour() override;
};

#endif //TITLESCREEN_HPP
