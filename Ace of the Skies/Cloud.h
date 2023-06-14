#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Cloud: public sf::Sprite
{public:
	//konstruktor destruktor
	Cloud(const sf::Texture& texture, sf::Vector2f position);
	~Cloud();

	bool ifonscreen(sf::Time DeltaTime);//metoda sprawdzaj¹ca czy obiekt w obrêbie ekranu i steruj¹ca ruchem
	
private:
	sf::Texture texture;
	int random_number;
};

