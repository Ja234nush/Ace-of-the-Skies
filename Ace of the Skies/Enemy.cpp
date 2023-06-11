#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init(const sf::Texture& texture)
{
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 150, 42));
	this->setPosition(100, 100);
}

void Enemy::Animate(sf::Time DeltaTime)
{
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 4;
		//std::cout << Del << std::endl;
		this->setTextureRect(sf::IntRect( 0, frame*42, 150, 42));
		accumulatedtime = 0;
	}
}

void Enemy::Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2f velocity, sf::Vector2u window)
{
}

void Enemy::borders(sf::FloatRect bounds, sf::Vector2u window)
{
}
