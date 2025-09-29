#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "State.hpp"
#include "Game.hpp"

class GameOver : public State {
	sf::Texture background;
	sf::Sprite spriteBackground;
	sf::Font font;
	sf::Text text;
	sf::Text text2;
public:
	GameOver(Game* game);
    void handleEvent(sf::Event &event) override;
    void update(float dt) override;
    void render(sf::RenderWindow &window) override;
};

#endif //GAMEOVER_HPP
