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
    m_Score.setPosition(750 , 40);
    m_Score.setCharacterSize(20);

    m_background.setTexture(m_context->m_asset->GetTexture(BACKGROUND));
    m_background.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
}

void GamePlay::ProcessInput()
{
}

void GamePlay::Update(sf::Time deltaTime)
{
}

void GamePlay::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_background);
    m_context->m_window->draw(m_Score);
  

    m_context->m_window->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}
