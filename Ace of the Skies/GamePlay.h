#pragma once
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "State.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
class GamePlay : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Time elapsed;
	bool m_is_paused;
	sf::Sprite m_background;
	sf::Text m_Score;
	sf::RectangleShape rectangle;
	Player player;
	Enemy enemy;
	sf::Vector2f direction;
	std::vector <sf::Sprite> cloud;
	int random_number;
	float v_y = -300;
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

