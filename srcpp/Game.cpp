#include "../incpp/Game.hpp"

Game::Game() {
	state = new TitleScreen(this);
}

void Game::changeState(State* newState) {
	state = newState;
}

void Game::testBehaviour() {
	state->testBehaviour();
}