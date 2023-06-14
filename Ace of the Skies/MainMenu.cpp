#include "MainMenu.h"
#include<ctime>;
#include<SFML/Window/Event.hpp>
#include "Cloud.h"


MainMenu::MainMenu(std::shared_ptr<Context>& context):m_context(context),
m_IsPlayButtonSelected(true), m_IsPlayButtonPressed(false),
m_IsExitButtonSelected(false), m_IsExitButtonPressed(false)
{
    //konstruktor
}

MainMenu::~MainMenu()
{//destruktor
}

void MainMenu::Init()
{   //wgrywanie �cie�ek do klasy enum
    srand(time(0));
	m_context->m_asset->AddFont(Main_Font,"Arial.ttf");
    m_context->m_asset->AddTexture(BACKGROUND, "Assets/background.png", true);
    m_context->m_asset->AddTexture(CLOUD1, "Assets/sprite_CLOUDS0 1.png", true);
    m_context->m_asset->AddTexture(CLOUD2, "Assets/sprite_CLOUDS1.png", true);
    m_context->m_asset->AddTexture(CLOUD3, "Assets/sprite_CLOUDS2.png", true);
    m_context->m_asset->AddTexture(CLOUD4, "Assets/sprite_CLOUDS3.png", true);
    m_context->m_asset->AddTexture(CLOUD5, "Assets/sprite_CLOUDS4.png", true);
    m_context->m_asset->AddTexture(CLOUD6, "Assets/sprite_CLOUDS5.png", true);
    m_context->m_asset->AddTexture(PLANE, "assets/plane.png");
    m_context->m_asset->AddTexture(HELI, "Assets/helicopter.png", true);
    m_context->m_asset->AddTexture(BALLON, "Assets/baloon.png", true);
    m_context->m_asset->AddTexture(BIRD, "Assets/bird.png", true);
    m_context->m_asset->AddTexture(FUEL, "Assets/gasoline.png", true);
    m_context->m_asset->AddTexture(HEAL, "Assets/wrench.png", true);
    m_context->m_asset->AddTexture(COIN, "Assets/coin.png", true);
    m_context->m_asset->AddTexture(BULLET, "Assets/bullet.png", true);
    m_context->m_asset->AddTexture(INSTRUCTION, "Assets/instruction.png", true);
    //ustawianie tekstu z tytu�em
	m_GameTitle.setFont(m_context->m_asset->GetFont(Main_Font));
	m_GameTitle.setString("Ace of the skies");
    m_GameTitle.setOrigin(m_GameTitle.getGlobalBounds().width / 2, m_GameTitle.getGlobalBounds().height / 2);
    m_GameTitle.setPosition((m_context->m_window->getSize().x/2)-60, (m_context->m_window->getSize().y / 2) - 200.f);
    m_GameTitle.setCharacterSize(50);
    //ustawianie tekstu z Play
    m_PlayButton.setFont(m_context->m_asset->GetFont(Main_Font));
    m_PlayButton.setString("Play");
    m_PlayButton.setOrigin(m_PlayButton.getGlobalBounds().width / 2, m_PlayButton.getGlobalBounds().height / 2);
    m_PlayButton.setPosition((m_context->m_window->getSize().x / 2)-10, (m_context->m_window->getSize().y/2)+10.f );
    m_PlayButton.setCharacterSize(30);
    //ustawianie instrukcji
    instruct.setTexture(m_context->m_asset->GetTexture(INSTRUCTION));
    instruct.setPosition(45, 330);
    instruct.setScale(3, 3);
    //ustawianie tekstu z Exit
    m_ExitButton.setFont(m_context->m_asset->GetFont(Main_Font));
    m_ExitButton.setString("Exit");
    m_ExitButton.setOrigin(m_ExitButton.getGlobalBounds().width / 2, m_ExitButton.getGlobalBounds().height / 2);
    m_ExitButton.setPosition((m_context->m_window->getSize().x / 2) - 10,( m_context->m_window->getSize().y / 2)+60.f);
    m_ExitButton.setCharacterSize(30);

    //ustawianie t�a
    m_background.setTexture(m_context->m_asset->GetTexture(BACKGROUND));
    m_background.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));
    
    for (int i = 0; i < 3; i++)
    {
        //losowanie i rzutowanie na typ Enum a nast�pnie inicjalizacja Cloud
        random_number = 2 + rand() % 6;
        AssetID randomCloud = static_cast<AssetID>(random_number);
        cloud.emplace_back(std::make_unique<Cloud>(m_context->m_asset->GetTexture(randomCloud), sf::Vector2f(500 * i + 800, rand() % 440)));
    }
}

void MainMenu::Update(sf::Time deltaTime)
{
    if (m_IsPlayButtonSelected)
    {   //zaznaczanie przycisku Play
        m_PlayButton.setFillColor(sf::Color::Blue);
        m_ExitButton.setFillColor(sf::Color::White);

    } 
    else
    {   //zaznaczanie przycisku Exit
        m_ExitButton.setFillColor(sf::Color::Blue);
        m_PlayButton.setFillColor(sf::Color::White);
    }
   
    
        //ruch i przestawianie pozycji chmur
        for (auto& i : cloud)
        {   
            if (!i->ifonscreen(deltaTime))
            {
                random_number = 2 + rand() % 6;
                AssetID randomCloud = static_cast<AssetID>(random_number);

                i->setTexture(m_context->m_asset->GetTexture(randomCloud));
                i->setPosition(sf::Vector2f(800, rand() % 440));
                i->setScale(0.5, 0.5);
            }
        }
}
void MainMenu::ProcessInput()
{
    sf::Event ev;
    
    while (m_context->m_window->pollEvent(ev))
    {

        if (ev.type == sf::Event::Closed)
        {   //zamkni�cie okna
            m_context->m_window->close();
            break;
        }
        if (ev.type == sf::Event::KeyPressed)
        {   //poruszanie si� po przyciskach Play i Exit
            switch (ev.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!m_IsPlayButtonSelected)
                {
                    m_IsPlayButtonSelected = true;
                        m_IsExitButtonSelected = false;
                }break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_IsExitButtonSelected)
                {
                    m_IsPlayButtonSelected = false;
                    m_IsExitButtonSelected = true;
                }break;
            }
            case sf::Keyboard::Return:
            {   //zatwierdzanie wyboru i przej�cie do stanu gry
                m_IsPlayButtonPressed = false;
                m_IsExitButtonPressed = false;
                if (m_IsPlayButtonSelected)
                {
                    m_IsPlayButtonPressed = true;
                    m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
                   

                }
                else
                {   // Wyj�cie z gry
                    m_IsExitButtonPressed = true;
                    m_context->m_window->close();
                    
                }break;
            }
            default:
                break;
            }
        }
    }
}
void MainMenu::Draw()
{
	m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_background);
  
    for (auto& i : cloud)
    {
        if (i != nullptr)
        {
            m_context->m_window->draw(*i);

        }
    }
    m_context->m_window->draw(m_GameTitle);
    m_context->m_window->draw(m_PlayButton);
    m_context->m_window->draw(m_ExitButton);
    m_context->m_window->draw(instruct);

	m_context->m_window->display();
}
