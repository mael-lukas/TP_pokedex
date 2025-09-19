#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "State.hpp"
#include "Game.hpp"

class GameOver : public State {
public:
	GameOver(Game* game);
	void testBehaviour() override;
};

#endif //GAMEOVER_HPP
