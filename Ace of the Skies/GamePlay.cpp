#include "GamePlay.h"

GamePlay::GamePlay(std::shared_ptr<Context>& context):m_context(context)
{//konstruktor
}

GamePlay::~GamePlay()
{//destruktor
}

void GamePlay::Init()
{   //inicjalizacja tekstÛw wyúwietlajπcyhc punkty
    m_Score.setFont(m_context->m_asset->GetFont(Main_Font));
    m_Score.setString("Score");
    m_Score.setPosition(650 , 560);
    m_Score.setCharacterSize(20);
    Score.setFont(m_context->m_asset->GetFont(Main_Font));
    Score.setPosition(730 , 560);
    Score.setCharacterSize(20);
    //inicjalizacja prostokπta na t≥o dla paskÛw
    rectangle.setSize(sf::Vector2f(800, 50));
    rectangle.setPosition(sf::Vector2f(0, 550));
    rectangle.setFillColor(sf::Color::Black);
    //inicjalizacja t≥a
    m_background.setTexture(m_context->m_asset->GetTexture(BACKGROUND));
    m_background.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
    //inicjalizacja gracza
    player.Init(m_context->m_asset->GetTexture(PLANE));
    sf::Clock clock;
        //tworzenie obiektÛw Cloud poprzez rzutowanie na Enum
        for (int i = 0; i < 4; i++)
        {
            
            random_number = 2 + rand() % 6;
           AssetID randomCloud = static_cast<AssetID>(random_number);
           cloud.emplace_back(std::make_unique<Cloud>(m_context->m_asset->GetTexture(randomCloud), sf::Vector2f(500 * i + 800, rand() % 440))); 
        }   
            //inicjalizacja paskÛw stanÛw i ich t≥a
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
    // Pobieranie i obs≥uga zdarzeÒ zwiπzanych z oknem
    while (m_context->m_window->pollEvent(ev))
    {
        
        if (ev.type == sf::Event::Closed)
        {   //zamkniÍcie okna
            m_context->m_window->close();
        }
        // Sprawdzenie, czy spacja zosta≥a naciúniÍta i up≥ynπ≥ odpowiedni czas od ostatniego strza≥u
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastshot.asSeconds() > 0.5)
        {   // Obliczenie pozycji startowej pocisku na podstawie pozycji gracza
            positionplayer.x = player.getPosition().x + player.getGlobalBounds().width/2;
            positionplayer.y = player.getPosition().y + player.getGlobalBounds().height/2;
            // Dodanie nowego pocisku do kontenera bullets
            bullets.emplace_back(std::make_unique<Bullet>(m_context->m_asset->GetTexture(BULLET),positionplayer ));
            // Zresetowanie czasu ostatniego strza≥u
            lastshot = sf::Time::Zero;
        }
    }
    //sprawdzanie stanÛw koÒca gry
    if (player.getFuel() <= 0 || player.getLives() <= 0)
    {   // Dodanie stanu GameOver do stosu stanÛw gry, przekazanie kontekstu gry i wyniku gracza
        m_context->m_states->Add(std::make_unique<GameOver>(m_context,player.getScore()), true);
    }

    
}

void GamePlay::Update(sf::Time deltaTime)
{
    player.Animate(deltaTime);//animacja gracza
    player.Movement(deltaTime, player.getGlobalBounds(),m_context->m_window->getSize());//ruch gracza
    lastspawned += deltaTime;//zwiÍkszanie czasu od ostatniego pojawienia siÍ Enemy
    lastspawnedbuff += deltaTime;//zwiÍkszanie czasu od ostatniego pojawienia siÍ Buffs
    fuelusage += deltaTime;//zwiÍkszanie czasu od ostatniego pobrania paliwa
    lastshot += deltaTime;//zwiÍkszanie czasu od ostatniego strza≥u
    progression += deltaTime;  ////zwiÍkszanie czasu od ostatniego zwiÍkszenia trudnoúci
    //ruch i przestawianie obiektÛw chmur
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
    //zwiÍkszenie poziomu trudnoúci wraz z czasem
    if (progression.asSeconds() > 15.f&& dificulty<5 )
    {
        dificulty++;
        progression = sf::Time::Zero;
    }
    //respienie przeciwnikÛw w zaleønoúci od mijajπcego czasu
    if(lastspawned.asSeconds()>(3-dificulty*0.3))
    {   //losowanie typu przeciwnika
        enemytype = rand() % 3;
        if (enemytype == 0)
        {   //losowanie pozycji przeciwnika
            position = sf::Vector2f(800.f, rand() % 500);
            //tworzenie wskaünika na Helicopter
            enemies.emplace_back(std::make_unique<Helicopter>(m_context->m_asset->GetTexture(HELI),position));
        }
        else if (enemytype == 1)
        {   //losowanie pozycji przeciwnika
            position = sf::Vector2f(800.f, rand() % 500);
            //tworzenie wskaünika na Baloon
            enemies.emplace_back(std::make_unique<Baloon>(m_context->m_asset->GetTexture(BALLON),position));
        }
        else if (enemytype == 2)
        {   //losowanie pozycji przeciwnika
            position = sf::Vector2f(800.f, rand() % 500);
            //tworzenie wskaünika na Bird
            enemies.emplace_back(std::make_unique<Bird>(m_context->m_asset->GetTexture(BIRD),position));
        }
        lastspawned = sf::Time::Zero;//zerowanie czasu od ostatniego respu
    }
    //respienie buffÛw w zaleønoúci od czasu 
    if(lastspawnedbuff.asSeconds()>(7+dificulty*0.3))
    {   //losowanie typu buffu
        bufftype = rand() % 4;
        if (bufftype == 0)
        {   //losownanie pozycji
            position = sf::Vector2f(rand() % 700, rand() % 500);
            //tworzenie wskaünika na Heal
            buffs.emplace_back(std::make_unique<Heal>(m_context->m_asset->GetTexture(HEAL),position));
        }
        else if (bufftype == 1||bufftype==3)
        {   //losownanie pozycji
            position = sf::Vector2f(rand() % 700, rand() % 500);
            //tworzenie wskaünika na Fuel
            buffs.emplace_back(std::make_unique<Fuel>(m_context->m_asset->GetTexture(FUEL),position));
        }
        else if (bufftype == 2)
        {   //losownanie pozycji
            position = sf::Vector2f(rand() % 700, rand() % 500);
            //tworzenie wskaünika na Coin
            buffs.emplace_back(std::make_unique<Coin>(m_context->m_asset->GetTexture(COIN),position));
        }
        lastspawnedbuff = sf::Time::Zero;//zerowanie czasu od ostatniego respu
    }
    //poruszanie i animacja dla przeciwnikÛw odpowiedniego typu
    for (auto& object : enemies)
    {
        if (object != nullptr)
        {   //rzutowanie aby okreúliÊ typ przeciwnika
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
    }
    //poruszanie  dla pociskÛw 
    for (auto& object : bullets)
    {
        if (object != nullptr)
        {
            object->fly(deltaTime);
        }
    }
    //zuøycie paliwa
    if (fuelusage.asSeconds() > 1)
    {
        player.setFuel(-3);
        fuelusage = sf::Time::Zero;
    }
    Score.setString( std::to_string(player.getScore()));//aktualizacja punktÛw
    //skalowanie paskÛw stanÛw
    health.setScale(player.getLives() / 100.f, 1);
    fuel.setScale(player.getFuel()/100.f, 1);
    //kolizja dla przeciwnikÛw
    for (auto& object : enemies)
    {
        if (object != nullptr)
        {   //kolizja Enemy,player
            if (object->getGlobalBounds().intersects(player.getGlobalBounds()))
            {   //usuwanie wskaünika i zmiana odpowiednich wartoúci w zaleønoúci od typu
                if (auto* helicopter = dynamic_cast<Helicopter*>(object.get()))
                {   
                    object.reset();
                    player.setLives(-20);
                    player.setScore(-10);
                }
                else if (auto* baloom = dynamic_cast<Baloon*>(object.get()))
                {
                    object.reset();
                    player.setLives(-10);
                    player.setScore(-5);
                }
                else if (auto* bird = dynamic_cast<Bird*>(object.get()))
                {
                    object.reset();
                    player.setLives(-5);
                    player.setScore(-5);
                }
            }
            //kolizja Enemy granice ekranu
            if (object != nullptr)
            {
                if (object->getPosition().x + object->getGlobalBounds().width < 0)
                {
                    object.reset();
                }
            }
            //kolizja Enemy,Bullet
            for (auto& shot : bullets)
            {   
                if (object != nullptr)
                {
                    if (shot != nullptr)
                    {   
                        if (object->getGlobalBounds().intersects(shot->getGlobalBounds()))
                        {   //zmiana poziomu zdrowia lub usuwanie wskaünika Enemy i Bullet
                            if (auto* helicopter = dynamic_cast<Helicopter*>(object.get()))
                            {   
                                if(helicopter->getlives() == 0)
                                {
                                    object.reset();
                                    shot.reset();
                                }
                                else
                                {
                                    helicopter->setlives();
                                    shot.reset();
                                }

                            }
                            else if (auto* baloom = dynamic_cast<Baloon*>(object.get()))
                            {
                                object.reset();
                                shot.reset();
                            }
                            else if (auto* bird = dynamic_cast<Bird*>(object.get()))
                            {
                                object.reset();
                                shot.reset();
                            }
                        }
                    }
                }
                //kolizja Bullet z granicami ekranu i usuwanie wskaünika
                if (shot != nullptr)
                {
                    if (shot->getPosition().x > 800)
                    {
                        shot.reset();
                    }
                }
            }
        }
    }
    //kolizja player z Buffs
    for (auto& object : buffs)
    {   
        if (object != nullptr)
        {   //usuwanie wskaünika i zmiana odpowiednich wartoúci w zaleønoúci od typu
            if (object->getGlobalBounds().intersects(player.getGlobalBounds()))
            {   
                if (auto* healt = dynamic_cast<Heal*>(object.get()))
                {
                    if (player.getLives() < 81)
                    {
                        player.setLives(20);
                    }
                    else if (player.getLives() < 100)
                    {
                        player.setLives(100 - player.getLives());
                    }
                    object.reset();
                }
                if (auto* fuelt = dynamic_cast<Fuel*>(object.get()))
                {
                    if (player.getFuel() < 51)
                    {
                        player.setFuel(50);
                    }
                    else if (player.getFuel() < 100)
                    {
                        player.setFuel(100 - player.getFuel());
                    }
                    object.reset();
                }
                if (auto* coint = dynamic_cast<Coin*>(object.get()))
                {
                    player.setScore(20);
                    object.reset();
                }
            }
        }
    }
}

void GamePlay::Draw()
{   //renderowanie ekranu 
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_background);
    //renderowanie Cloud 
    for (auto& i : cloud)
    {
        if (i != nullptr)
        {
            m_context->m_window->draw(*i);

        }
    }
    //renderowanie Enemy 
    for (auto& object : enemies)
    {
        if (object != nullptr)
        {
            m_context->m_window->draw(*object);

        }
    }
    //renderowanie Bullet 
    for (auto& object : bullets)
    {
        if (object != nullptr)
        {
            m_context->m_window->draw(*object);

        }
    }
    //renderowanie Buff 
    for (auto& object : buffs)
    {
        if (object != nullptr)
        {
            m_context->m_window->draw(*object);
        }
    }
    //renderowanie paskÛw stanu 
    m_context->m_window->draw(rectangle);
    m_context->m_window->draw(m_Score);
    m_context->m_window->draw(Score);
    m_context->m_window->draw(underfuel);
    m_context->m_window->draw(underhealth);
    m_context->m_window->draw(fuel);
    m_context->m_window->draw(health);
    //renderowanie gracza
    m_context->m_window->draw(player);
   
  

    m_context->m_window->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}
