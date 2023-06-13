#include "Bullet.h"

Bullet::Bullet(const sf::Texture& texture, const sf::Vector2f& playerPosition)
{
	this->setTexture(texture);
	this->setPosition(playerPosition);

}

Bullet::~Bullet()
{
}

void Bullet::fly(sf::Time deltaTime)
{
	this->move(200.f * deltaTime.asSeconds(), 0);
}
