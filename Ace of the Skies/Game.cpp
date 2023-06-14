#include "Game.h"
#include "MainMenu.h"

//konstruktory destruktory definicje
Game::Game() : m_context(std::make_shared<Context>())
{
    // Inicjalizacja okna SFML i stanu MainMenu
    m_context->m_window->create(video, "Ace of the skies", sf::Style::Titlebar | sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}
Game::~Game()
{
  //destruktor
}

//funkcje 

void  Game::run()
{  //wgrywanie muzyki 
    if (!music.openFromFile("Assets/music.wav"))
    {
        std::cout << "error" << std::endl;
    }
    music.setVolume(0.5);
    //odtwarzanie muzyki
    music.play();
    sf::Clock clock;
    sf::Time TimeSinceFrame = sf::Time::Zero;
    //warunki ograniczenia od�wie�ania na sekund� 
    m_context->m_window->setFramerateLimit(40);
    //p�tla dla otwartego okna
    while (m_context->m_window->isOpen())
    {   sf::Time elapsed = clock.restart();
        TimeSinceFrame += elapsed;
        // Sprawdzenie, czy up�yn�� wystarczaj�cy czas od ostatniej klatki
        if (TimeSinceFrame>SecPerFrame)
            {
            
                // Przetwarzanie zmian stan�w gry
                 m_context->m_states->ProcessStateChanges();
                 // Przetwarzanie wej�cia dla aktualnego stanu gry
                 m_context->m_states->getCurrent()->ProcessInput();
                 // Aktualizacja stanu gry
                 m_context->m_states->getCurrent()->Update(SecPerFrame);
                 // Rysowanie obiekt�w dla aktualnego stanu gry
                 m_context->m_states->getCurrent()->Draw();
               
                 TimeSinceFrame = sf::Time::Zero;
     
            }
    }
}








