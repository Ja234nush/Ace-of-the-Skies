#pragma once
#include<Sfml/System/Time.hpp>
namespace Engine
{
	class State
	{	
	public:
		State() {};
		virtual ~State() {};
		// Czyste wirtualne funkcje, kt�re musz� by� zaimplementowane przez klasy pochodne
		virtual void Init()=0;// Inicjalizacja stanu
		virtual void ProcessInput() = 0;// Przetwarzanie danych wej�ciowych 
		virtual void Update(sf::Time deltaTime) = 0; //Aktualizowanie stanu
		virtual void Draw() = 0;//rysowanie stanu

		// Opcjonalne funkcje, kt�re mo�na przes�oni�
		virtual void Pause() {};
		virtual void Start() {};
	};
}
