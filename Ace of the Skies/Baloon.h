#pragma once
#include "Enemy.h"
class Baloon:public Enemy
{
private:
	sf::Texture texture;
	int frame = 0;
	float frameTime = 1.0f / 10;
	float accumulatedtime = 0;
	sf::Vector2f speed = sf::Vector2f(-70.f, 0.f);
	int lives = 1;
public:
	Baloon(const sf::Texture& texture, sf::Vector2f position);
	~Baloon();
	void Animate(sf::Time DeltaTime);
	void Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window);
	void setlives();
	int getlives();
};

