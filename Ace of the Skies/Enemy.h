#pragma once

#include <SFML/Graphics.hpp>
class Enemy: public sf::Sprite
{   private:
        sf::Texture texture;
        int frame = 0; // Numer aktualnej klatki animacji
        float frameTime = 1.0f / 10; // Czas trwania jednej klatki animacji
        float accumulatedtime = 0; // ca³kowity czas dla animacji
        sf::Vector2f speed = sf::Vector2f(100.f, 70.f);
      
    public:
        //konstruktor destruktor
        Enemy();
        ~Enemy();

        virtual void borders(sf::FloatRect bounds, sf::Vector2u window);//metoda sprawdzaj¹ca czy obiekty wychodz¹ poza ekran i przenosz¹ca je

    
   
};

