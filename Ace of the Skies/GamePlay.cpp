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
    m_Score.setPosition(650 , 560);
    m_Score.setCharacterSize(20);
    Score.setFont(m_context->m_asset->GetFont(Main_Font));
    Score.setPosition(730 , 560);
    Score.setCharacterSize(20);

    rectangle.setSize(sf::Vector2f(800, 50));
    rectangle.setPosition(sf::Vector2f(0, 550));
    rectangle.setFillColor(sf::Color::Black);

    m_background.setTexture(m_context->m_asset->GetTexture(BACKGROUND));
    m_background.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
 
    player.Init(m_context->m_asset->GetTexture(PLANE));
    sf::Clock clock;
    
        for (int i = 0; i < 5; i++)
        {
            
            random_number = 2 + rand() % 6;
           AssetID randomCloud = static_cast<AssetID>(random_number);
           cloud.emplace_back(std::make_unique<Cloud>(m_context->m_asset->GetTexture(randomCloud), sf::Vector2f(500 * i + 800, rand() % 440))); 
        }   
            health = sf::RectangleShape((sf::Vector2f(200.f, 20.f)));
            health.setFillColor(sf::Color::Red);
            health.setPosition(400.f, 565.f); 
            underhealth = sf::RectangleShape((sf::Vector2f(206.f, 24.f)));
            underhealth.setFillColor(sf::Color::White);
            underhealth.setPosition(397.f, 563.f);
            fuel = sf::RectangleShape((sf::Vector2f(200.f, 20.f)));
            fuel.setFillColor(sf::Color::Yellow);
            fuel.setPosition(100.f, 565.f); 
            underfuel = sf::RectangleShape((sf::Vector2f(206.f, 24.f)));
            underfuel.setFillColor(sf::Color::White);
            underfuel.setPosition(97.f, 563.f);
            
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        if (lastshot.asSeconds() > 0.5)
        {
            positionplayer.x = player.getPosition().x + player.getGlobalBounds().width/2;
            positionplayer.y = player.getPosition().y + player.getGlobalBounds().height/2;
            bullets.emplace_back(std::make_unique<Bullet>(m_context->m_asset->GetTexture(BULLET),positionplayer ));
            lastshot = sf::Time::Zero;
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
    lastspawnedbuff += deltaTime;
    fuelusage += deltaTime;
    lastshot += deltaTime;
    progression += deltaTime;
    if (progression.asSeconds() > 15.f && dificulty<4)
    {
        dificulty++;
        progression = sf::Time::Zero;
    }
    if(lastspawned.asSeconds()>(3-dificulty*0.3))
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
    

    if(lastspawnedbuff.asSeconds()>(7+dificulty*0.3))
    {
        bufftype = rand() % 4;
        if (bufftype == 0)
        {   
            position = sf::Vector2f(rand() % 700, rand() % 500);
            buffs.emplace_back(std::make_unique<Heal>(m_context->m_asset->GetTexture(HEAL),position));
        }
        else if (bufftype == 1||bufftype==3)
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
    }
    for (auto& object : bullets)
    {
        object->fly(deltaTime);
    }
    if (fuelusage.asSeconds() > 1)
    {
        player.setFuel(-3);
        fuelusage = sf::Time::Zero;
    }
    Score.setString( std::to_string(player.getScore()));
    health.setScale(player.getLives() / 100, 1);
    fuel.setScale(player.getFuel()/100.f, 1);
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
    for (auto& object : bullets)
    {
        m_context->m_window->draw(*object);
    }
    for (auto& object : buffs)
    {   
        m_context->m_window->draw(*object);
    }
    m_context->m_window->draw(rectangle);
    m_context->m_window->draw(m_Score);
    m_context->m_window->draw(Score);
    m_context->m_window->draw(underfuel);
    m_context->m_window->draw(underhealth);
    m_context->m_window->draw(fuel);
    m_context->m_window->draw(health);

    m_context->m_window->draw(player);
   
  

    m_context->m_window->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}
