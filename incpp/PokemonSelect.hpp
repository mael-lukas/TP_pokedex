#ifndef POKEMONSELECT_HPP
#define POKEMONSELECT_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"

class PokemonSelect : public State {
	std::string name;
	std::vector<Pokemon> team;
public:
	PokemonSelect(Game* game,std::string name,std::vector<Pokemon> team);
	void handleEvent(sf::Event &event);
	void update(float dt);
	void render(sf::RenderWindow &window);
};

#endif //POKEMONSELECT_HPP
