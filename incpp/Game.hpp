#ifndef GAME_HPP
#define GAME_HPP

#include "State.hpp"
#include "Pokemon_PC.hpp"
#include "TitleScreen.hpp"

class Game {
	State* state;
	sf::RenderWindow window;
	Pokemon_PC pc;

public:
	Game(Pokemon_PC &pc);
	void changeState(State* newState);
	void run();
	Pokemon_PC &getPC();
};

#endif //GAME_HPP
