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
	std::vector <std::unique_ptr<Cloud>> cloud;// Wektor przechowuj¹cy wskaŸniki na Cloud
	sf::Text m_GameTitle;//tekst z tytu³em gry
	sf::Text m_PlayButton;//tekst przycisku Play
	sf::Text m_ExitButton;//tekst przycisku Exit
	sf::Sprite m_background;//tekstura t³a
	sf::Sprite instruct;//tekstura schematu sterowania
	
	
	sf::Vector2u world = sf::Vector2u(1200, 900);
	
	bool m_IsPlayButtonSelected;//sprawdzanie czy Graj jest zaznaczony
	bool m_IsPlayButtonPressed;//sprawdzanie czy Graj jest wciœniêty

	bool m_IsExitButtonSelected;//sprawdzanie czy Exit jest zaznaczony
	bool m_IsExitButtonPressed;//sprawdzanie czy Exit jest wciœniêty

	int random_number;
	float v_y = -300;
public:
	//konstruktor destruktor
	MainMenu(std::shared_ptr<Context> &context);
	~MainMenu();

	void Init() override; // Inicjalizacja stanu
	void ProcessInput() override; // Przetwarzanie wejœcia
	void Update(sf::Time deltaTime) override; // Aktualizacja stanu
	void Draw() override; // Rysowanie stanu
};

