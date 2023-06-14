#include "Heal.h"


Heal::Heal(const sf::Texture& texture, sf::Vector2f position)
{	//konstruktor obiektu nadaj¹cy teksturê i pozycjê
	this->setTexture(texture);
	this->setPosition(position);
}

Heal::~Heal()
{//destruktor
}
