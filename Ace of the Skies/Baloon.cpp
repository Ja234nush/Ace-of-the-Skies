#include "Baloon.h"
#include <random>
#include <ctime>
Baloon::Baloon(const sf::Texture& texture)
{
	srand(time(NULL));
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 52, 84));
	this->setPosition(700, rand() % 500);
}

Baloon::~Baloon()
{
}

void Baloon::Animate(sf::Time DeltaTime)
{
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 5;
		//std::cout << Del << std::endl;
		this->setTextureRect(sf::IntRect(frame * 55, 0, 55, 84));
		accumulatedtime = 0;
	}
}

void Baloon::Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window)
{
	this->move(speed.x * DeltaTime.asSeconds(), speed.y);
	this->borders(bounds, window);
}

void Baloon::setlives()
{
	lives -= 1;
}

int Baloon::getlives()
{
	return lives;
}
