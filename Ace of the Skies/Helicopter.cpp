#include "Helicopter.h"
#include <random>
#include <ctime>


Helicopter::Helicopter(const sf::Texture& texture, sf::Vector2f position)
{	//inicjalizacja ziarna dla losowoœci i konstruktor obiektu
	srand(time(NULL));
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 150, 42));
	this->setPosition(position);
}

Helicopter::~Helicopter()
{//destruktor
}

void Helicopter::Animate(sf::Time DeltaTime)
{	//animacja helikoptera
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
{	//poruszanie siê helikoptera w zale¿noœci od po³o¿enia gracza, w górê lub dó³
	if (directiony > (this->getPosition().y-30))
	{
		this->move(speed.x * DeltaTime.asSeconds(), speed.y * DeltaTime.asSeconds());
	}
	else if (directiony <= (this->getPosition().y-30))
	{
		this->move(speed.x * DeltaTime.asSeconds(), speed.y * DeltaTime.asSeconds() * (-1));
	}
	this->borders( bounds,window);//odwo³anie do funkcji klasy Enemy
}

void Helicopter::setlives()
{	//zmienianie poziomu ¿ycia
	lives -= 1;
}

int Helicopter::getlives()
{	//pobieranie poziomu ¿ycia
	return lives;
}


