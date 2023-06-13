#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Assetmanager.h"
#include "Statemanager.h"
#include <iostream>

enum AssetID
{
	Main_Font = 0,
	BACKGROUND = 1,
	CLOUD1 = 2,
	CLOUD2 = 3,
	CLOUD3 = 4,
	CLOUD4 = 5,
	CLOUD5 = 6,
	CLOUD6 = 7,
	PLANE = 8,
	HELI = 9,
	BALLON = 10,
	BIRD = 11,
	COIN = 12,
	FUEL = 13,
	HEAL = 14
};

struct Context
{
	std::unique_ptr<Engine::Assetmanager> m_asset;
	std::unique_ptr<Engine::StateManager> m_states;
	std::unique_ptr<sf::RenderWindow> m_window;

	Context()
	{
		m_asset = std::make_unique<Engine::Assetmanager>();
		m_states = std::make_unique<Engine::StateManager>();
		m_window = std::make_unique<sf::RenderWindow>();
	}
};
//klasa ktora zarzadza oknem i procesami gry
class Game
{
private:
	std::shared_ptr<Context> m_context;
	sf::Time SecPerFrame = sf::seconds(1.f / 40.f);
	sf::VideoMode video = sf::VideoMode(800, 600);
	
public:
	//konstruktory / destruktory
	Game();
	virtual ~Game();

	//deklaracje funkcji
	void run();
	


};


