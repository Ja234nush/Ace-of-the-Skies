#include "Bird.h"

Bird::Bird(const sf::Texture& texture)
{	srand(time(NULL));
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 62, 52));
	this->setPosition(700, rand()%500);
	
}

Bird::~Bird()
{
}

void Bird::Animate(sf::Time DeltaTime)
{
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 8;
		//std::cout << Del << std::endl;
		this->setTextureRect(sf::IntRect(frame * 62,0 , 62, 52));
		accumulatedtime = 0;
	}
}

void Bird::Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window)
{	
	this->move((-50 - rand() % 100) * DeltaTime.asSeconds(), ((100- rand() % 200))*DeltaTime.asSeconds());
	this->borders(bounds, window);
}

void Bird::setlives()
{
	lives -= 1;
}

int Bird::getlives()
{
	return lives;
}
