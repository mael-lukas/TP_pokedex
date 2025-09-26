#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

class Game;

class State {
	protected:
	Game* game;
	State(Game* game);

	public:
	virtual ~State() = default;

	virtual void handleEvent(sf::Event &event) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow &window) = 0;
};

#endif //STATE_HPP
