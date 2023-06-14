#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Cloud: public sf::Sprite
{public:
	//konstruktor destruktor
	Cloud(const sf::Texture& texture, sf::Vector2f position);
	~Cloud();

	bool ifonscreen(sf::Time DeltaTime);//metoda sprawdzaj�ca czy obiekt w obr�bie ekranu i steruj�ca ruchem
	
private:
	sf::Texture texture;
	int random_number;
};

