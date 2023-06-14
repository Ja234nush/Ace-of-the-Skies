#include "Bird.h"

Bird::Bird(const sf::Texture& texture, sf::Vector2f position)
{	//konstruktor inijcuj¹cy ziarno dla losowoœci oraz teksturê i pozycjê 
	srand(time(NULL));
	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 62, 52));
	this->setPosition(position);
	random = rand() % 100;
}

Bird::~Bird()
{///destruktor
}

void Bird::Animate(sf::Time DeltaTime)
{	//animacja dla ptaka
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 8;
		this->setTextureRect(sf::IntRect(frame * 62,0 , 62, 52));
		accumulatedtime = 0;
		
	}
}

void Bird::Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window)
{	//ruch
	this->move((-50 - (random%50)) * DeltaTime.asSeconds(), ((50- random))*DeltaTime.asSeconds());
	this->borders(bounds, window);
}


