#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include "State.hpp"
#include "Game.hpp"
#include "Exploration.hpp"

class TitleScreen : public State {
    sf::Texture background;
    sf::Sprite spriteBackground;
    sf::Font font;
    sf::Font font2;
    sf::Text title;
    sf::Text indication;
    float timePassed = 0.f;

public:
    TitleScreen(Game* game);
    void handleEvent(sf::Event &event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;

};

#endif //TITLESCREEN_HPP
