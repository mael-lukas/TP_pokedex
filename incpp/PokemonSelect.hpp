#ifndef POKEMONSELECT_HPP
#define POKEMONSELECT_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"
#include "GameOver.hpp"

class PokemonSelect : public State {
	std::string name;
	std::vector<Pokemon> team;

	std::vector<sf::Keyboard::Key> konamiCodeBuffer = {};
	sf::Clock bufferClock;
public:
	PokemonSelect(Game* game,std::string name,std::vector<Pokemon> team);
	void handleEvent(sf::Event &event) override;
	void update(float dt) override;
	void render(sf::RenderWindow &window) override;
};

#endif //POKEMONSELECT_HPP
