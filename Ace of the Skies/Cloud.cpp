#include "Cloud.h"

Cloud::Cloud(const sf::Texture& texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}

Cloud::~Cloud()
{
}

bool Cloud::ifonscreen(sf::Time DeltaTime)
{
	if (this->getGlobalBounds().width + this->getPosition().x > 0)
	{
		this->move(-300 * DeltaTime.asSeconds(), 0);
		return true;
	}
	return false;
}