#include "Helicopter.h"
#include <random>
#include <ctime>


Helicopter::Helicopter(const sf::Texture& texture, sf::Vector2f position)
{
	srand(time(NULL));
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 150, 42));
	this->setPosition(position);
}

Helicopter::~Helicopter()
{
}

void Helicopter::Animate(sf::Time DeltaTime)
{
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 4;
		//std::cout << Del << std::endl;
		this->setTextureRect(sf::IntRect(0, frame * 42, 150, 42));
		accumulatedtime = 0;
	}
}

void Helicopter::Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window,float directiony)
{	
	if (directiony > (this->getPosition().y-30))
	{
		this->move(speed.x * DeltaTime.asSeconds(), speed.y * DeltaTime.asSeconds());
	}
	else if (directiony <= (this->getPosition().y-30))
	{
		this->move(speed.x * DeltaTime.asSeconds(), speed.y * DeltaTime.asSeconds() * (-1));
	}
	this->borders( bounds,window);
}

void Helicopter::setlives()
{
	lives -= 1;
}

int Helicopter::getlives()
{
	return lives;
}


