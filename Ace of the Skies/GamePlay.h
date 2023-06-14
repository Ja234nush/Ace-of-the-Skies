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
	std::shared_ptr<Context> m_context;// Wspó³dzielony wskaŸnik na obiekt typu Context
	sf::Time elapsed; // Up³yniêty czas
	sf::Sprite m_background; // T³o gry
	sf::Text m_Score; // Tekst z napiesem wynik
	sf::Text Score; // Tekst z wynikiem
	sf::RectangleShape rectangle;
	Player player; // Obiekt gracza
	std::vector <std::unique_ptr<Cloud>> cloud;// Wektor unikalnych wskaŸników na obiekty typu Cloud
	std::vector<std::unique_ptr<Enemy>> enemies;// Wektor unikalnych wskaŸników na obiekty typu Enemy
	std::vector<std::unique_ptr<BUFFS>> buffs;// Wektor unikalnych wskaŸników na obiekty typu BUFFS
	std::vector<std::unique_ptr<Bullet>> bullets;// Wektor unikalnych wskaŸników na obiekty typu Bullet
	int random_number;
	sf::Time lastspawned;// Czas od ostatniego pojawienia siê przeciwnika
	sf::Time lastspawnedbuff;// Czas od ostatniego pojawienia siê buffa
	sf::Time lastshot=sf::Time::Zero;// Czas od ostatniego wystrza³u
	sf::Time fuelusage=sf::Time::Zero;// Czas od ostatniego zu¿ycia paliwa
	sf::Time progression=sf::Time::Zero;// Czas od ostatniego podniesienia trudnoœci
	int dificulty = 1;//wspó³czynnik trudnoœci 
	sf::Vector2f position;
	sf::Vector2f positionplayer;//pozycja gracza
	sf::RectangleShape health;// Pasek zdrowia
	sf::RectangleShape underhealth;//t³o paska zdrownia
	sf::RectangleShape fuel;// Pasek paliwa
	sf::RectangleShape underfuel;//t³o paska paliwa
	int enemytype;//zmienna do losowania typu przeciwnika
	int bufftype;//zmienna do losowania typu buffa
	
	
public:
	// Konstruktor przyjmuj¹cy wskaŸnik na Context /destruktor
	GamePlay(std::shared_ptr<Context> &context);
	~GamePlay();

	void Init() override; // Inicjalizacja stanu gry
	void ProcessInput() override; // Przetwarzanie wejœcia
	void Update(sf::Time deltaTime) override; // Aktualizacja gry
	void Draw() override; // Renderowanie ekranu
	void Pause() override;
	void Start() override;
};

