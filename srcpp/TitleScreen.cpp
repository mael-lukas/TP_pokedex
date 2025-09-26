#include "../incpp/TitleScreen.hpp"
#include <iostream>

TitleScreen::TitleScreen(Game* game) : State(game) {
    font.loadFromFile("../Pokemon Solid.ttf");
    font2.loadFromFile("../arial.ttf");
    background.loadFromFile("../qsutbgg.jpg");
    title.setFont(font);
    title.setString("Waaaa les POKEMONS \n  (mais c'est ouf)");
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::Black);
    title.setPosition(250, 250);
    indication.setFont(font2);
    indication.setString("Press Enter to start");
    indication.setCharacterSize(70);
    indication.setFillColor(sf::Color::Black);
    indication.setPosition(450, 650);
    spriteBackground.setTexture(background);
    spriteBackground.setScale(0.65f,0.5f);
    spriteBackground.setPosition(-300, -200);

}

void TitleScreen::handleEvent(sf::Event &event) {
    //std::cout << "TitleScreen" << std::endl;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        game->changeState(new Exploration(game));
    }
}

void TitleScreen::update(float dt) {
    timePassed += dt;
}

void TitleScreen::render(sf::RenderWindow &window) {
    window.draw(spriteBackground);
    window.draw(title);
    if ((int)(timePassed * 3) % 3 != 0) {
        window.draw(indication);
    }
}