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
  //  cloud.resize(3);
    
        for (int i = 0; i < 3; i++)
        {
            
            random_number = 2 + rand() % 6;
           AssetID randomCloud = static_cast<AssetID>(random_number);
           cloud.emplace_back(std::make_unique<Cloud>(m_context->m_asset->GetTexture(randomCloud), sf::Vector2f(500 * i + 800, rand() % 440))); 
    }
        
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
    }
    
}

void GamePlay::Update(sf::Time deltaTime)
{
    player.Animate(deltaTime);
    player.Movement(deltaTime, player.getGlobalBounds(),m_context->m_window->getSize());
    
    for (auto& i : cloud)
    {
        if(!i->ifonscreen(deltaTime))
        {
            random_number = 2 + rand() % 6;
            AssetID randomCloud = static_cast<AssetID>(random_number);

            i->setTexture(m_context->m_asset->GetTexture(randomCloud));
            i->setPosition(sf::Vector2f(800, rand() % 440));
            i->setScale(0.5, 0.5);
        }
    }
    lastspawned += deltaTime;
    if(lastspawned.asSeconds()>(3-dificulty*0.5))
    {
        enemytype = rand() % 3;
        if (enemytype == 0)
        {   
            position = sf::Vector2f(800.f, rand() % 500);
            enemies.emplace_back(std::make_unique<Helicopter>(m_context->m_asset->GetTexture(HELI),position));
        }
        else if (enemytype == 1)
        {
            position = sf::Vector2f(800.f, rand() % 500);
            enemies.emplace_back(std::make_unique<Baloon>(m_context->m_asset->GetTexture(BALLON),position));
        }
        else if (enemytype == 2)
        {
            position = sf::Vector2f(800.f, rand() % 500);
            enemies.emplace_back(std::make_unique<Bird>(m_context->m_asset->GetTexture(BIRD),position));
        }
        lastspawned = sf::Time::Zero;
    }
    lastspawnedbuff += deltaTime;
   // std::cout << lastspawnedbuff.asSeconds() << std::endl;
    if(lastspawnedbuff.asSeconds()>(7+dificulty*0.5))
    {
        bufftype = rand() % 3;
        if (bufftype == 0)
        {   
            position = sf::Vector2f(rand() % 700, rand() % 500);
            buffs.emplace_back(std::make_unique<Heal>(m_context->m_asset->GetTexture(HEAL),position));
        }
        else if (bufftype == 1)
        {
            position = sf::Vector2f(rand() % 700, rand() % 500);
            buffs.emplace_back(std::make_unique<Fuel>(m_context->m_asset->GetTexture(FUEL),position));
        }
        else if (bufftype == 2)
        {
            position = sf::Vector2f(rand() % 700, rand() % 500);
            buffs.emplace_back(std::make_unique<Coin>(m_context->m_asset->GetTexture(COIN),position));
        }
        lastspawnedbuff = sf::Time::Zero;
    }
    for (auto& object : enemies)
    {
        if (auto* helicopter = dynamic_cast<Helicopter*>(object.get()))
        {
            helicopter->Animate(deltaTime);
            helicopter->Movement(deltaTime, helicopter->getGlobalBounds(), m_context->m_window->getSize(), player.getPosition().y);
        }
        else if (auto* baloom = dynamic_cast<Baloon*>(object.get()))
        {
            baloom->Animate(deltaTime);
            baloom->Movement(deltaTime, baloom->getGlobalBounds(), m_context->m_window->getSize());
        }
        else if (auto* bird = dynamic_cast<Bird*>(object.get()))
        {
            bird->Animate(deltaTime);
            bird->Movement(deltaTime, bird->getGlobalBounds(), m_context->m_window->getSize());
        }
    }iter = 1;
}

void GamePlay::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_background);
    for (auto& i : cloud)
    {
        m_context->m_window->draw(*i);
    }
    for (auto& object : enemies)
    {
        m_context->m_window->draw(*object);
    }
    for (auto& object : buffs)
    {   
        std::cout << 2 << std::endl;
        m_context->m_window->draw(*object);
    }
    m_context->m_window->draw(rectangle);
    m_context->m_window->draw(m_Score);
    m_context->m_window->draw(player);
   
  

    m_context->m_window->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}
