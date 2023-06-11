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
 
    player.Init(m_context->m_asset->GetTexture(PLANE));
    sf::Clock clock;
    cloud.resize(3);
    
        for (int i = 0; i < 3; i++)
        {
            if (i < cloud.size())  // Sprawdzenie, czy i jest w zakresie indeksów wektora clouds
            {
            random_number = 2 + rand() % 6;
           AssetID randomCloud = static_cast<AssetID>(random_number);
            cloud[i].setTexture(m_context->m_asset->GetTexture(randomCloud));
            cloud[i].setPosition(sf::Vector2f(500 * i + 800, rand() % 440));

                }
    }
    enemy.Init(m_context->m_asset->GetTexture(HELI));
}

void GamePlay::ProcessInput()
{
    sf::Event ev;

    while (m_context->m_window->pollEvent(ev))
    {
        

        if (ev.type == sf::Event::Closed)
        {   //zamkniêcie okna
            m_context->m_window->close();
        }
        if(sf::Keyboard::isKeyPressed( sf::Keyboard::Up))
        {
            direction.y = -1.0;
        }
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Down))
        {
            direction.y = 1.0;
        }
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Left))
        {
            direction.x = -1.0; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction.x = 1.0; 
        }
        
        
    }
    
}

void GamePlay::Update(sf::Time deltaTime)
{
   

    player.Animate(deltaTime);
    player.Movement(deltaTime, player.getGlobalBounds(),direction,m_context->m_window->getSize());
    enemy.Animate(deltaTime);
    direction.x = 0, direction.y = 0;
    
    for (int i = 0; i < 3; i++)
        {
        if (i < cloud.size())  // Sprawdzenie, czy i jest w zakresie indeksów wektora clouds
            {
                 if (cloud[i].getGlobalBounds().width + cloud[i].getPosition().x > 0)
                 {
                  cloud[i].move(v_y * deltaTime.asSeconds(), 0);
                 }
                 else
                 {



                   random_number = 2 + rand() % 6;
                   AssetID randomCloud = static_cast<AssetID>(random_number);

                   cloud[i].setTexture(m_context->m_asset->GetTexture(randomCloud));
                   
                   cloud[i].setPosition(sf::Vector2f(50 * i + 800, rand() % 440));
                   cloud[i].setScale(0.5, 0.5);

                 }
            }
    }
}

void GamePlay::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_background);
    for (int i = 0; i < 3; i++)
    {
        m_context->m_window->draw(cloud[i]);
    }
    m_context->m_window->draw(rectangle);
    m_context->m_window->draw(m_Score);
    m_context->m_window->draw(player);
    m_context->m_window->draw(enemy);
  

    m_context->m_window->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}
