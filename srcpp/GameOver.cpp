#include "../incpp/GameOver.hpp"
#include <iostream>

GameOver::GameOver(Game* game) {
  	this->game = game;
  	background.loadFromFile("../qsutbgg.jpg");
  	spriteBackground.setTexture(background);
  	spriteBackground.setScale(0.65f,0.5f);
  	spriteBackground.setPosition(-300, -200);
  	font.loadFromFile("../Pokemon Solid.ttf");
  	text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Black);
    text.setPosition(450, 250);
    text2.setFont(font);
    text2.setString("(try harder next time)");
    text2.setCharacterSize(100);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(150, 400);
}

void GameOver::handleEvent(sf::Event &event) {
}

void GameOver::update(float dt) {
}

void GameOver::render(sf::RenderWindow &window) {
	window.draw(spriteBackground);
    window.draw(text);
    window.draw(text2);
}