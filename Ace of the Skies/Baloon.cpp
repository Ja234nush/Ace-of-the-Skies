#include "Baloon.h"

Baloon::Baloon(const sf::Texture& texture, sf::Vector2f position)
{//konstruktor inijcuj¹cy teksturê i pozycjê 
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 52, 84));
	this->setPosition(position);
}

Baloon::~Baloon()
{//destruktor
}

void Baloon::Animate(sf::Time DeltaTime)
{	//animacja obiektu
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 5;
		this->setTextureRect(sf::IntRect(frame * 55, 0, 55, 84));
		accumulatedtime = 0;
	}
}

void Baloon::Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window)
{	//poruszanie
	this->move(speed.x * DeltaTime.asSeconds(), speed.y);
	this->borders(bounds, window);
}

void Baloon::setlives()
{	//zmienianie poziomu ¿ycia 
	lives -= 1;
}

int Baloon::getlives()
{//pobieranie poziomu ¿ycia 
	return lives;
}
