#include "Fuel.h"

Fuel::Fuel(const sf::Texture& texture, sf::Vector2f position)
{	//konstruktor obiektu nadaj�cy tekstur� i pozycj�
	this->setTexture(texture);
	this->setPosition(position);
}

Fuel::~Fuel()
{	//destruktor
}
