#ifndef ARENA_HPP
#define ARENA_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"

class Arena : public State {

public:
	Arena(Game* game);
	void handleEvent(sf::Event &event) override;
	void update(float dt) override;
	void render(sf::RenderWindow &window) override;
};

#endif //ARENA_HPP
