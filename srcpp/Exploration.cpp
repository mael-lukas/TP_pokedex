#include "../incpp/Exploration.hpp"
#include <iostream>

Exploration::Exploration(Game* game) : State(game) {
	playerCharacter.loadFromFile("../Sprite-0001.png");
	background.loadFromFile("../Sprite-0002.png");
	spriteBackground.setTexture(background);
	spriteBackground.setScale(6.1f,6.f);
	spriteBackground.setPosition(0, 0);
	sprite.setTexture(playerCharacter);
	sprite.setScale(4.f,4.f);
	sprite.setPosition(750, 750);
	updateSprite();

	sf::FloatRect eventBoxTest = sf::FloatRect(0,0,1550,400);
	sf::RectangleShape eventBoxShape = sf::RectangleShape(sf::Vector2f(eventBoxTest.width, eventBoxTest.height));
	eventBoxShape.setPosition(eventBoxTest.left, eventBoxTest.top);
	eventBoxShape.setFillColor(sf::Color(255, 0, 0, 128));

	EventZone eventZoneTest {eventBoxTest,
						     eventBoxShape,
				     "Inezia",
		             {Pokedex::getInstance()->findByName("Emolga"),
		             	Pokedex::getInstance()->findByName("Flaaffy"),
		             	Pokedex::getInstance()->findByName("Zebstrika")
		             }
	};

	eventZonesTest.push_back(eventZoneTest);

}

void Exploration::updateSprite() {
	sprite.setTextureRect(sf::IntRect(frameWidth * currentFrame, frameHeight * direction, frameWidth, frameHeight));
}

void Exploration::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		/*switch (event.key.code) {
			case sf::Keyboard::Z:
				direction = UP;
				velocity.y = -speed;
				break;
			case sf::Keyboard::S:
				direction = DOWN;
				velocity.y = +speed;
				break;
			case sf::Keyboard::Q:
				direction = LEFT;
				velocity.x = -speed;
				break;
			case sf::Keyboard::D:
				direction = RIGHT;
				velocity.x = +speed;
				break;
			default:
				break;
		}*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			velocity.y = -speed;
			direction = UP;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			velocity.y = speed;
			direction = DOWN;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			velocity.x = -speed;
			direction = LEFT;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			velocity.x = speed;
			direction = RIGHT;
		}
	}
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::S) {
			velocity.y = 0;
		}
		if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::D) {
			velocity.x = 0;
		}
	}
}

void Exploration::update(float dt) {
	sprite.move(velocity * dt);
	if (velocity.x != 0 || velocity.y != 0) {
		animationTime += dt;
		if (animationTime >= animationDuration) {
			animationTime = 0.f;
			currentFrame = (currentFrame + 1) % frameCount;
			updateSprite();
		}
	}
	else {
		currentFrame = 0;
		updateSprite();
	}
	if (sprite.getGlobalBounds().intersects(eventZonesTest[0].collisionZone)) {
		std::cout << "Collision" << std::endl;
		game->changeState(new PokemonSelect(game,eventZonesTest[0].name,eventZonesTest[0].team));
	}
}

void Exploration::render(sf::RenderWindow &window) {
	window.draw(spriteBackground);
	window.draw(sprite);
	window.draw(eventZonesTest[0].eventBoxShape);
}

