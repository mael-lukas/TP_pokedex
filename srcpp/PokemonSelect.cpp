#include "../incpp/PokemonSelect.hpp"
#include <iostream>

PokemonSelect::PokemonSelect(Game* game,std::string name,std::vector<Pokemon> team) : State(game) {
	this->name = name;
	this->team = team;
}

void PokemonSelect::handleEvent(sf::Event &event) {
}

void PokemonSelect::update(float dt) {
}

void PokemonSelect::render(sf::RenderWindow &window) {
	int counter = 0;
	for (Pokemon pokemon : team) {
		sf::Texture texture;
		texture.loadFromFile(pokemon.getSpritePath());
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setScale(3.f,3.f);
		sprite.setPosition((counter%2)*200 + 1100+2, (counter/2)*200);
		window.draw(sprite);
		counter++;
	}
}