#ifndef EXPLORATION_HPP
#define EXPLORATION_HPP

#include "State.hpp"
#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Game.hpp"
#include "Capture.hpp"
#include "Arena.hpp"
#include "PokemonSelect.hpp"

class Exploration : public State {
	sf::Texture background;
	sf::Sprite spriteBackground;
	sf::Texture playerCharacter;
	sf::Sprite sprite;
	const int frameWidth = 32;
	const int frameHeight = 33;
	const int frameCount = 3;
	int currentFrame = 0;
	float animationTime = 0.f;
	float animationDuration = 0.15f;

	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	Direction direction;

	sf::Vector2f velocity;
	float speed = 300.f;

	struct EventZone {
		sf::FloatRect collisionZone;
		sf::RectangleShape eventBoxShape;
		std::string name;
		std::vector<Pokemon> team;
	};
	std::vector<EventZone> eventZonesTest;

public:
	Exploration(Game* game);
	void updateSprite();
	void handleEvent(sf::Event &event) override;
	void update(float dt) override;
	void render(sf::RenderWindow &window) override;
};

#endif //EXPLORATION_HPP
