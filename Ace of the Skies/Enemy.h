#pragma once

#include <SFML/Graphics.hpp>
class Enemy: public sf::Sprite
{   private:
        sf::Texture texture;
        int frame = 0;
        float frameTime = 1.0f / 10;
        float accumulatedtime = 0;
        sf::Vector2f speed = sf::Vector2f(100.f, 70.f);
      
    public:
        Enemy();
        ~Enemy();

        virtual void borders(sf::FloatRect bounds, sf::Vector2u window);

    
   
};

