#include "../incpp/PokemonSelect.hpp"
#include <iostream>

PokemonSelect::PokemonSelect(Game* game,std::string name,std::vector<Pokemon> team) {
	this->game = game;
	this->name = name;
	this->team = team;
}

void PokemonSelect::handleEvent(sf::Event &event) {
	std::vector<sf::Keyboard::Key> konamiCode = {sf::Keyboard::Up,sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::B,sf::Keyboard::A};
	if (event.type == sf::Event::KeyPressed) {
		bufferClock.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			game->changeState(new Exploration(game));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			konamiCodeBuffer.push_back(sf::Keyboard::Up);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			konamiCodeBuffer.push_back(sf::Keyboard::Down);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			konamiCodeBuffer.push_back(sf::Keyboard::Left);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			konamiCodeBuffer.push_back(sf::Keyboard::Right);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			konamiCodeBuffer.push_back(sf::Keyboard::B);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			konamiCodeBuffer.push_back(sf::Keyboard::A);
		}
		if (konamiCodeBuffer == konamiCode) {
			game->changeState(new GameOver(game));
		}
	}
}

void PokemonSelect::update(float dt) {
	if (bufferClock.getElapsedTime().asSeconds() >= 2.0f) {
		konamiCodeBuffer = {};
	}
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
	counter = 0;
	for (Pokemon pokemon : game->getPC().getPokemons()) {
		sf::Texture texture;
		texture.loadFromFile(pokemon.getSpritePath());
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setScale(3.f,3.f);
		sprite.setPosition((counter%2)*200, (counter/2)*200);
		window.draw(sprite);
		counter++;
	}
}