#include "Cloud.h"

Cloud::Cloud(const sf::Texture& texture, sf::Vector2f position)
{	//konstruktor inicjuj¹cy teksturê i pozycjê
	this->setTexture(texture);
	this->setPosition(position);
}

Cloud::~Cloud()
{//destruktor
}

bool Cloud::ifonscreen(sf::Time DeltaTime)
{	//sprawdzanie granic okna dla Cloud i poruszanie
	if (this->getGlobalBounds().width + this->getPosition().x > 0)
	{
		this->move(-300 * DeltaTime.asSeconds(), 0);
		return true;
	}
	return false;
}