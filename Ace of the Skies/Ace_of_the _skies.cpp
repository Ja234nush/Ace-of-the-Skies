#include<iostream>
#include"Game.h"

int main()
{   //tworzenie silnika gry
    Game game;
    //tworzenie petli glownej
    while (game.running())
    {
        //aktualizacja gry
        game.update();
        //renderowanie
        game.render();
    }



    return 0;
}