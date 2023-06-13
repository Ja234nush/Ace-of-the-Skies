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
	std::shared_ptr<Context> m_context;
	sf::Text losing;
	sf::Text scoring;
	int points;
public:
	GameOver(std::shared_ptr<Context>& context, int score);
	~GameOver();
	void Init()override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw()override;
};

