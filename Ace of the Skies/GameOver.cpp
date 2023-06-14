#include "GameOver.h"

GameOver::GameOver(std::shared_ptr<Context>& context, int score) :m_context(context)
{	//konstruktor
	points = score;
}

GameOver::~GameOver()
{//destruktor
}

void GameOver::Init()
{	//inicjalizacja tekstów o przegranej i punktach
	scoring.setFont(m_context->m_asset->GetFont(Main_Font));
	scoring.setPosition(270.f, 300.f);
	scoring.setString("Your score: "+std::to_string(points));
	scoring.setCharacterSize(40);
	losing.setFont(m_context->m_asset->GetFont(Main_Font));
	losing.setPosition(200.f, 200.f);
	losing.setString(" GAME OVER ");
	losing.setCharacterSize(60);

}

void GameOver::ProcessInput()
{
	sf::Event ev;
	//sprawdzanie zdarzeñ
	while (m_context->m_window->pollEvent(ev))
	{

		if (ev.type == sf::Event::Closed)
		{   //zamkniêcie okna
			m_context->m_window->close();
			break;
		}
	}
}

void GameOver::Update(sf::Time deltaTime)
{
}

void GameOver::Draw()
{	//renderowanie okna
	m_context->m_window->clear(sf::Color::Black);
	m_context->m_window->draw(losing);
	m_context->m_window->draw(scoring);
	m_context->m_window->display();
}
