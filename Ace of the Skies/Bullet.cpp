#include "Bullet.h"

Bullet::Bullet(const sf::Texture& texture, const sf::Vector2f& playerPosition)
{	//konstruktor inicjuj�cy tekstur� i pozycj�
	this->setTexture(texture);
	this->setPosition(playerPosition);

}

Bullet::~Bullet()
{//destruktor
}

void Bullet::fly(sf::Time deltaTime)
{	//poruszanie Bullet
	this->move(200.f * deltaTime.asSeconds(), 0);
}
