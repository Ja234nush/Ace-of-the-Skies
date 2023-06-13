#include "Heal.h"


Heal::Heal(const sf::Texture& texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}

Heal::~Heal()
{
}
