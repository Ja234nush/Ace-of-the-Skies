#pragma once
#include<stack>
#include<memory>

#include "State.h"
namespace Engine
{
	class StateManager
	{
	private:
		std::stack<std::unique_ptr<State>> m_stateStack;// Stos przechowuj¹cy wskaŸniki na stany gry
		std::unique_ptr<State> m_newState; // WskaŸnik na nowy stan gry, który ma byæ dodany

		bool m_add;
		bool m_replace;
		bool m_remove;
	public:
		//konstruktor destruktor
		StateManager() ;
		~StateManager();

		void Add(std::unique_ptr<State> toAdd, bool replace = false); // Dodawanie nowego stanu do stosu
		void PopCurrent(); // Usuwanie aktualnego stanu ze stosu
		void ProcessStateChanges();// Przetwarzanie zmian stanu
		std::unique_ptr<State>& getCurrent();// Pobieranie referencji do aktualnego stanu
	};
}
