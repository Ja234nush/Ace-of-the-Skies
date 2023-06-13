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
#include "Bullet.h"
#include "GameOver.h"

class GamePlay : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Time elapsed;
	sf::Sprite m_background;
	sf::Text m_Score;
	sf::Text Score;
	sf::RectangleShape rectangle;
	Player player;
	std::vector <std::unique_ptr<Cloud>> cloud;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<BUFFS>> buffs;
	std::vector<std::unique_ptr<Bullet>> bullets;
	int random_number;
	sf::Time lastspawned;
	sf::Time lastspawnedbuff;
	sf::Time lastshot=sf::Time::Zero;
	sf::Time fuelusage=sf::Time::Zero;
	sf::Time progression=sf::Time::Zero;
	int dificulty = 1;
	int iter = 1;
	sf::Vector2f position;
	sf::Vector2f positionplayer;
	sf::RectangleShape health;
	sf::RectangleShape underhealth;
	sf::RectangleShape fuel;
	sf::RectangleShape underfuel;
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

