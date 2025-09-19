#include "Game.hpp"

Game::Game(){
	state = new TitleScreen(this);
}

void Game::changeState(State* state){
    
}

void Game::testBehaviour(){
    state->testBehaviour();
}