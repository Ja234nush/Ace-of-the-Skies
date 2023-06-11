#pragma once
#include <memory>
#include<SFML/Graphics/Text.hpp>
#include <random>
#include <vector>

#include "State.h"
#include "Game.h"
#include "GamePlay.h"
class MainMenu:public Engine::State
{private:
	std::shared_ptr<Context> m_context;
	sf::Text m_GameTitle;
	sf::Text m_PlayButton;
	sf::Text m_ExitButton;
	sf::Sprite m_background;
	std::vector <sf::Sprite> clouds;
	
	sf::Vector2u world = sf::Vector2u(1200, 900);
	
	bool m_IsPlayButtonSelected;
	bool m_IsPlayButtonPressed;

	bool m_IsExitButtonSelected;
	bool m_IsExitButtonPressed;

	int random_number;
	float v_y = -300;
public:
	MainMenu(std::shared_ptr<Context> &context);
	~MainMenu();
	 void Init() override;
	 void ProcessInput() override;
	 void Update(sf::Time deltaTime) override;
	 void Draw() override;
};

