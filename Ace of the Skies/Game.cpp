#include "Game.h"

//konstruktory destruktory definicje
Game::Game() {
    // Inicjalizacja okna SFML
    this->Initvariable();
    this->Initwindow();
}
Game::~Game()
{
    delete this->window;
}

//funkcje private

//utworzenie okna
void Game::Initwindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(video), "Tower defense", sf::Style::Titlebar | sf::Style::Close);
}

//inicjalizacja zmiennych
void Game::Initvariable()
{
    this->window = nullptr;
    this->video.width = 1000;
    this->video.height = 600;
}

//sprawdzenie czy okno dzia³a
const bool Game::running() const
{
    return this->window->isOpen();
}

//funkcje

//sprawdzanie zdarzeñ
void Game::pollevents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            window->close();
            break;

        }
    }
}
void  Game::render()
{  //czyszczenie i rysowanie okna
    this->window->clear(sf::Color::Red);
    this->window->display();
}
void  Game::update()
{    //sprawdzanie zdarzeñ
    this->pollevents();

}







