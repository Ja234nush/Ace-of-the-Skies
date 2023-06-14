#pragma once
#include "Enemy.h"
#include <random>
#include <ctime>
class Bird:public Enemy
{	private:
	sf::Texture texture;
	int frame = 0;// Numer bie��cej klatki animacji
	float frameTime = 1.0f / 10;// Czas trwania jednej klatki animacji
	float accumulatedtime = 0;// Ca�kowity czas dla animacji
	int random ;

public:
	//konstruktor destruktor
	Bird(const sf::Texture& texture, sf::Vector2f position);
	~Bird();

	void Animate(sf::Time DeltaTime);// Metoda animuj�ca ptaka
	void Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window);// Metoda steruj�ca ruchem ptaka
};

