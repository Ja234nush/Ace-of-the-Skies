#include "GamePlay.h"

GamePlay::GamePlay(std::shared_ptr<Context>& context):m_context(context)
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::Init()
{
    m_Score.setFont(m_context->m_asset->GetFont(Main_Font));
    m_Score.setString("Score");
    m_Score.setPosition(700 , 550);
    m_Score.setCharacterSize(20);

    rectangle.setSize(sf::Vector2f(800, 50));
    rectangle.setPosition(sf::Vector2f(0, 550));
    rectangle.setFillColor(sf::Color::Black);

    m_background.setTexture(m_context->m_asset->GetTexture(BACKGROUND));
    m_background.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
}

void GamePlay::ProcessInput()
{
    sf::Event ev;

    while (m_context->m_window->pollEvent(ev))
    {
        //switch (ev.type)

        if (ev.type == sf::Event::Closed)
        {   //zamkniêcie okna
            m_context->m_window->close();
        }
    }
}

void GamePlay::Update(sf::Time deltaTime)
{
}

void GamePlay::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_background);
    m_context->m_window->draw(rectangle);
    m_context->m_window->draw(m_Score);
  

    m_context->m_window->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}
