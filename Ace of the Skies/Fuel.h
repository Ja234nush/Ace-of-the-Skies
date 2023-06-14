#pragma once
#include <SFML/Graphics.hpp>
#include "BUFFS.h"
class Fuel:public BUFFS
{
public:
	//konstruktor destruktor
	Fuel(const sf::Texture& texture, sf::Vector2f position);
	~Fuel();
};

