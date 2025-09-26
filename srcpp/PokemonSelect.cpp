#include "../incpp/PokemonSelect.hpp"
#include <iostream>

PokemonSelect::PokemonSelect(Game* game,std::string name,std::vector<Pokemon> team) : State(game) {

}

void PokemonSelect::testBehaviour() {
	std::cout << "PokemonSelect" << std::endl;
	game->changeState(new Exploration(game));
}
