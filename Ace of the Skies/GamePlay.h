#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Helicopter.h"
#include "Baloon.h"
#include "Bird.h"
#include "Cloud.h"
#include "Coin.h"
#include "Fuel.h"
#include "Heal.h"

class GamePlay : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Time elapsed;
	//bool m_is_paused;
	sf::Sprite m_background;
	sf::Text m_Score;
	sf::RectangleShape rectangle;
	Player player;
	std::vector <std::unique_ptr<Cloud>> cloud;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<BUFFS>> buffs;
	int random_number;
	sf::Time lastspawned;
	sf::Time lastspawnedbuff;
	int dificulty = 1;
	int iter = 1;
	sf::Vector2f position;
	int enemytype;
	int bufftype;
	
	
public:
	GamePlay(std::shared_ptr<Context> &context);
	~GamePlay();
	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw() override;
	void Pause() override;
	void Start() override;
};

