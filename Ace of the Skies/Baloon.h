#pragma once
#include "Enemy.h"
class Baloon:public Enemy
{
private:
	sf::Texture texture;
	int frame = 0;// Numer bie��cej klatki animacji
	float frameTime = 1.0f / 10;// Czas trwania jednej klatki animacji
	float accumulatedtime = 0;// Ca�kowity czas dla animacji
	sf::Vector2f speed = sf::Vector2f(-70.f, 0.f);
	int lives = 1;
public:
	//konstruktor destruktor
	Baloon(const sf::Texture& texture, sf::Vector2f position);
	~Baloon();

	void Animate(sf::Time deltaTime); // Metoda animuj�ca balona
	void Movement(sf::Time deltaTime, sf::FloatRect bounds, sf::Vector2u window); // Metoda steruj�ca ruchem balona
	void setlives(); // Metoda zmieniaj�ca liczb� �y� balona
	int getlives(); // Metoda zwracaj�ca liczb� �y� balona
};

