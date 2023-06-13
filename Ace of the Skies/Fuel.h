#pragma once
#include <SFML/Graphics.hpp>
#include "BUFFS.h"
class Fuel:public BUFFS
{
public:
	Fuel(const sf::Texture& texture, sf::Vector2f position);
	~Fuel();
};

