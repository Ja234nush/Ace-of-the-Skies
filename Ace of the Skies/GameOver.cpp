#include "GameOver.h"

GameOver::GameOver(std::shared_ptr<Context>& context, int score) :m_context(context)
{
	points = score;
}

GameOver::~GameOver()
{
}

void GameOver::Init()
{
	scoring.setFont(m_context->m_asset->GetFont(Main_Font));
	scoring.setPosition(350.f, 300.f);
	scoring.setString("Your score: "+std::to_string(points));
	scoring.setCharacterSize(40);
	losing.setFont(m_context->m_asset->GetFont(Main_Font));
	losing.setPosition(300.f, 200.f);
	losing.setString(" GAME OVER ");
	losing.setCharacterSize(60);

}

void GameOver::ProcessInput()
{
	sf::Event ev;

	while (m_context->m_window->pollEvent(ev))
	{
		//switch (ev.type)

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
{
	m_context->m_window->clear(sf::Color::Black);
	m_context->m_window->draw(losing);
	m_context->m_window->draw(scoring);
	m_context->m_window->display();
}
