#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include "Game.h"


class Player
{
public:
	Player(std::shared_ptr<Context>& context);
	~Player();
};

