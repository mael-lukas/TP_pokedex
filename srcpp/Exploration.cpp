#include "../incpp/Exploration.hpp"
#include <iostream>

Exploration::Exploration(Game* game) {
	this->game = game;
	playerCharacter.loadFromFile("../Sprite-0001.png");
	background.loadFromFile("../Sprite-0002.png");
	spriteBackground.setTexture(background);
	spriteBackground.setScale(6.1f,6.f);
	spriteBackground.setPosition(0, 0);
	sprite.setTexture(playerCharacter);
	sprite.setScale(4.f,4.f);
	sprite.setPosition(750, 750);
	updateSprite();


/////////////////////////////////////////////// Defining event trigger areas for every gym leader ////////////////////////////////////////////////////////////////////////
	sf::FloatRect cherenEvent = sf::FloatRect(0,0,180,360);
	EventZone cherenZone {cherenEvent,"Cheren",
	{Pokedex::getInstance()->findByName("Patrat"),Pokedex::getInstance()->findByName("Lillipup")}
	};
	eventZones.push_back(cherenZone);

	sf::FloatRect roxieEvent = sf::FloatRect(198,0,180,360);
	EventZone roxieZone {roxieEvent,"Roxie",
	{Pokedex::getInstance()->findByName("Koffing"),Pokedex::getInstance()->findByName("Whirlipede")}
	};
	eventZones.push_back(roxieZone);

	sf::FloatRect burghEvent = sf::FloatRect(394,0,180,360);
	EventZone burghZone {burghEvent,"Burgh",
	{Pokedex::getInstance()->findByName("Swadloon"),Pokedex::getInstance()->findByName("Dwebble"),Pokedex::getInstance()->findByName("Leavanny")}
	};
	eventZones.push_back(burghZone);

	sf::FloatRect elesaEvent = sf::FloatRect(590,0,180,360);
	EventZone elesaZone {elesaEvent,"Elesa",
		{Pokedex::getInstance()->findByName("Emolga"),Pokedex::getInstance()->findByName("Flaaffy"),Pokedex::getInstance()->findByName("Zebstrika")}
	};
	eventZones.push_back(elesaZone);

	sf::FloatRect clayEvent = sf::FloatRect(780,0,180,360);
	EventZone clayZone {clayEvent,"Clay",
		{Pokedex::getInstance()->findByName("Krokorok"),Pokedex::getInstance()->findByName("Sandslash"),Pokedex::getInstance()->findByName("Excadrill")}
	};
	eventZones.push_back(clayZone);

	sf::FloatRect skylaEvent = sf::FloatRect(980,0,180,360);
	EventZone skylaZone {skylaEvent,"Skyla",
		{Pokedex::getInstance()->findByName("Swoobat"),Pokedex::getInstance()->findByName("Skarmory"),Pokedex::getInstance()->findByName("Swanna")}
	};
	eventZones.push_back(skylaZone);

	sf::FloatRect draydenEvent = sf::FloatRect(1175,0,180,360);
	EventZone draydenZone {draydenEvent,"Drayden",
		{Pokedex::getInstance()->findByName("Druddigon"),Pokedex::getInstance()->findByName("Flygon"),Pokedex::getInstance()->findByName("Haxorus")}
	};
	eventZones.push_back(draydenZone);

	sf::FloatRect marlonEvent = sf::FloatRect(1370,0,180,360);
	EventZone marlonZone {marlonEvent,"Marlon",
		{Pokedex::getInstance()->findByName("Carracosta"),Pokedex::getInstance()->findByName("Wailord"),Pokedex::getInstance()->findByName("Jellicent")}
	};
	eventZones.push_back(marlonZone);

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
	for (EventZone ez : eventZones) {
		if (sprite.getGlobalBounds().intersects(ez.collisionZone)) {
			std::cout << "Collision" << std::endl;
			game->changeState(new PokemonSelect(game,ez.name,ez.team));
		}
	}
}

void Exploration::render(sf::RenderWindow &window) {
	window.draw(spriteBackground);
	window.draw(sprite);
}

