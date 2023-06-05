#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
//klasa ktora zarzadza oknem i procesami gry
class Game
{
private:
	//inicjalizacja zmiennych i okna
	void Initwindow();
	void Initvariable();
	//zmienne okna i wydarzen
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode video;
	sf::Clock clock;
public:
	//konstruktory / destruktory
	Game();
	virtual ~Game();

	//warunek czy okno dziala
	const bool running() const;
	//deklaracje funkcji
	void render();
	void update();
	void pollevents();


};


