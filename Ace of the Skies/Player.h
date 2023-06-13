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
    void Movement(sf::Time DeltaTime,sf::FloatRect bounds, sf::Vector2u window);
    void borders(sf::FloatRect bounds, sf::Vector2u window);
    void setLives(int i);
    void setFuel(int i);
    void setScore(int i);
    void getLives();
    void getFuel();
    void getScore();
   

private:
    sf::Texture texture;
    int frame = 0;
    float frameTime = 1.0f / 10;
    float accumulatedtime = 0;
    int lives = 100;
    int fuel = 100;
    int score = 0;
   

    sf::Vector2f direction=sf::Vector2f(0.f,0.f);
    sf::Vector2f speed=sf::Vector2f(100.f, 80.f);
    sf::Vector2f acceleration=sf::Vector2f(0.f, 0.4);
};

