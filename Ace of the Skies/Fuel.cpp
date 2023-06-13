#include "Fuel.h"

Fuel::Fuel(const sf::Texture& texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}

Fuel::~Fuel()
{
}
