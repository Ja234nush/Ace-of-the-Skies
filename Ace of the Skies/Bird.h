#pragma once
#include "Enemy.h"
class Bird:public Enemy
{	private:
	sf::Texture texture;
	int frame = 0;
	float frameTime = 1.0f / 10;
	float accumulatedtime = 0;
	int lives = 1;
	int random ;

public:
	Bird(const sf::Texture& texture, sf::Vector2f position);
	~Bird();
	void Animate(sf::Time DeltaTime);
	void Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window);
	void setlives();
	int getlives();
};
