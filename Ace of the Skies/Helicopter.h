#pragma once
#include"Enemy.h"
class Helicopter:public Enemy
{
private:
    sf::Texture texture;
    int frame = 0;
    float frameTime = 1.0f / 10;
    float accumulatedtime = 0;
    sf::Vector2f speed = sf::Vector2f(-100.f, 35.f);
    int lives = 2;

public:
    Helicopter(const sf::Texture& texture,sf::Vector2f position);
    ~Helicopter();

     void Animate(sf::Time DeltaTime);
     void Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window,float directiony);
     void setlives();
     int getlives();
};

