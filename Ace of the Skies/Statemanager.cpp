#pragma once
#include "Statemanager.h"

Engine::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false)
{//konstruktor
}

Engine::StateManager::~StateManager()
{//destruktor
}

void Engine::StateManager::Add(std::unique_ptr<State> toAdd, bool replace)
{	// Dodawanie nowego stanu do stosu
	m_add = true;
	m_newState = std::move(toAdd);
	m_replace = replace;
}

void Engine::StateManager::PopCurrent()
{	// Usuwanie aktualnego stanu ze stosu
	m_remove = true;

}

void Engine::StateManager::ProcessStateChanges()
{	// Przetwarzanie zmian stan�w
	if (m_remove && (!m_stateStack.empty()))
	{
		m_stateStack.pop();
		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Start();
		}m_remove = false;
	}
	if (m_add)
	{
		if (m_replace && (!m_stateStack.empty()))
		{
			m_stateStack.pop();
			m_replace = false;
		}
		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Start();
		}
		m_stateStack.push(std::move(m_newState));
		m_stateStack.top()->Init();
		m_stateStack.top()->Start();
		m_add = false;
	}
}	
	

std::unique_ptr<Engine::State>& Engine::StateManager::getCurrent()
{	// Pobieranie aktualnego stanu
	return m_stateStack.top();
}
