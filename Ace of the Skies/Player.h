#pragma once
#include <list>
#include <SFML/Graphics.hpp>



class Player : public sf::Sprite
{
public:
    Player();
    ~Player();

    void Init(const sf::Texture &texture);
    void Animate(sf::Time DeltaTime);
    void Movement(sf::Time DeltaTime,sf::FloatRect bounds,sf::Vector2f velocity, sf::Vector2u window);
    void borders(sf::FloatRect bounds, sf::Vector2u window);
    
private:
    sf::Texture texture;
    int frame = 0;
    float frameTime = 1.0f / 10;
    float accumulatedtime = 0;
    sf::Vector2f speed=sf::Vector2f(100.f, 70.f);
    sf::Vector2f gravity=sf::Vector2f(0.f, 20.f);
};

