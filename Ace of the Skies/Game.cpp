#include "Game.h"
#include "MainMenu.h"

//konstruktory destruktory definicje
Game::Game() : m_context(std::make_shared<Context>())
{
    // Inicjalizacja okna SFML
    m_context->m_window->create(video, "Ace of the skies", sf::Style::Titlebar | sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}
Game::~Game()
{
  
}

//funkcje 

void  Game::run()
{  
    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color::Red);

    sf::Clock clock;
    sf::Time TimeSinceFrame = sf::Time::Zero;
    m_context->m_window->setFramerateLimit(40);
    while (m_context->m_window->isOpen())
    {   sf::Time elapsed = clock.restart();
        TimeSinceFrame += elapsed;
        if (TimeSinceFrame>SecPerFrame)
            {
            
    
                 m_context->m_states->ProcessStateChanges();
                 m_context->m_states->getCurrent()->ProcessInput();
                 m_context->m_states->getCurrent()->Update(SecPerFrame);
                 m_context->m_states->getCurrent()->Draw();
                 //std::cout << "1:  " << TimeSinceFrame.asSeconds() << "/    2:  " << SecPerFrame.asSeconds() << std::endl;

                 TimeSinceFrame = sf::Time::Zero;
     
            }
    }
}








