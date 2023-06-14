#pragma once
#include <SFML/Graphics.hpp>
#include "BUFFS.h"
class Coin:public BUFFS
{public:
	//konstruktor destruktor
	Coin(const sf::Texture& texture, sf::Vector2f position);
	~Coin();
};

