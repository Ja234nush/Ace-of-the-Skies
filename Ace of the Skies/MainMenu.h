#pragma once
#include <memory>
#include<SFML/Graphics/Text.hpp>

#include "State.h"
#include "Game.h"
class MainMenu:public Engine::State
{private:
	std::shared_ptr<Context> m_context;
	sf::Text m_GameTitle;
	sf::Text m_PlayButton;
	sf::Text m_ExitButton;
	
	bool m_IsPlayButtonSelected;
	bool m_IsPlayButtonPressed;

	bool m_IsExitButtonSelected;
	bool m_IsExitButtonPressed;
public:
	MainMenu(std::shared_ptr<Context> &context);
	~MainMenu();
	 void Init() override;
	 void ProcessInput() override;
	 void Update(sf::Time deltaTime) override;
	 void Draw() override;
};

