#include "../incpp/Game.hpp"
#include <SFML/Graphics.hpp>

Game::Game():window(sf::VideoMode(1550, 1080), "WAAAAA LES POKEMOOOOONS") {
	state = new TitleScreen(this);
}

void Game::changeState(State* newState) {
	state = newState;
}

void Game::testBehaviour() {
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			state->handleEvent(event);
		}
		float dt = clock.restart().asSeconds();
		state->update(dt);
		window.clear();
		state->render(window);
		window.display();
	}
	//state->testBehaviour();
}