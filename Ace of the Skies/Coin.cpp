#include "Coin.h"

Coin::Coin(const sf::Texture& texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}

Coin::~Coin()
{
}
