#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Assetmanager.h"
#include "Statemanager.h"

enum AssteID
{
	Main_Font = 0
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
	sf::Time SecPerFrame = sf::seconds(1.f / 60.f);
	
public:
	//konstruktory / destruktory
	Game();
	virtual ~Game();

	//deklaracje funkcji
	void run();
	


};


