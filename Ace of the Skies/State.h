#pragma once
#include<Sfml/System/Time.hpp>
namespace Engine
{
	class State
	{	
	public:
		State() {};
		virtual ~State() {};
		// Czyste wirtualne funkcje, które musz¹ byæ zaimplementowane przez klasy pochodne
		virtual void Init()=0;// Inicjalizacja stanu
		virtual void ProcessInput() = 0;// Przetwarzanie danych wejœciowych 
		virtual void Update(sf::Time deltaTime) = 0; //Aktualizowanie stanu
		virtual void Draw() = 0;//rysowanie stanu

		// Opcjonalne funkcje, które mo¿na przes³oniæ
		virtual void Pause() {};
		virtual void Start() {};
	};
}
