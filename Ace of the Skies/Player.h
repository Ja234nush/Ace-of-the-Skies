#pragma once
#include <list>
#include <SFML/Graphics.hpp>



class Player : public sf::Sprite
{
public:
    //konstruktor destruktor
    Player();
    ~Player();

    void Init(const sf::Texture& texture); // Inicjalizacja gracza
    void Animate(sf::Time DeltaTime); // Animacja gracza
    void Movement(sf::Time DeltaTime, sf::FloatRect bounds, sf::Vector2u window); // Poruszanie siê gracza
    void borders(sf::FloatRect bounds, sf::Vector2u window); // Ograniczenia planszy i odbijanie od nich
    void setLives(int i); // Ustawienie poziomu ¿ycia
    void setFuel(int i); // Ustawienie poziomu paliwa
    void setScore(int i); // Ustawienie liczby punktów
    int getLives(); // Pobranie poziomu ¿ycia
    int getFuel(); // Pobranie poziomu paliwa
    int getScore(); // Pobranie liczby punktów
   

private:
    sf::Texture texture;
    int frame = 0; // Numer klatki animacji
    float frameTime = 1.0f / 10; // Czas trwania jednej klatki animacji
    float accumulatedtime = 0; //  czas animacji
    int lives = 100;
    int fuel = 100;
    int score = 0;
   

    sf::Vector2f direction=sf::Vector2f(0.f,0.f);// Kierunek poruszania siê gracza
    sf::Vector2f speed=sf::Vector2f(100.f, 80.f);// prêdkoœæ
    sf::Vector2f acceleration=sf::Vector2f(0.f, 0.4);// przyspieszenie swobodne
};

