#pragma once
#include <memory>
#include<SFML/Graphics/Text.hpp>
#include <random>
#include <vector>

#include "State.h"
#include "Game.h"
#include "GamePlay.h"
class GameOver:public::Engine::State
{
private:
	std::shared_ptr<Context> m_context;// Wsp�dzielony wska�nik na obiekt typu Context
	sf::Text losing; // Tekst informuj�cy o przegranej
	sf::Text scoring; // Tekst z wynikiem
	int points; // Liczba zdobytych punkt�w
public:
	GameOver(std::shared_ptr<Context>& context, int score);
	~GameOver();
	void Init()override;// Inicjalizacja stanu gry po zako�czeniu
	void ProcessInput() override;// Przetwarzanie wej�cia
	void Update(sf::Time deltaTime) override;// Aktualizacja  gry
	void Draw()override;// Renderowanie ekranu
};

