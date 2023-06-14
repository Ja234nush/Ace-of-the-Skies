#pragma once
#include <SFML/Graphics.hpp>
#include "BUFFS.h"
class Heal:public BUFFS
{
public:
	//konstruktor destruktor
	Heal(const sf::Texture& texture, sf::Vector2f position);
	  ~Heal();
};

