#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Cloud: public sf::Sprite
{public:
	Cloud(const sf::Texture& texture, sf::Vector2f position);
	~Cloud();
	bool ifonscreen(sf::Time DeltaTime);
	
private:
	sf::Texture texture;
	int random_number;
};

