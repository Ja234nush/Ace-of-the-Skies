#pragma once
#include <SFML/Graphics.hpp>
class Bullet:public sf::Sprite
{public:
	Bullet(const sf::Texture& texture, const sf::Vector2f& playerPosition);
		~Bullet();
		void fly(sf::Time deltaTime);
};

