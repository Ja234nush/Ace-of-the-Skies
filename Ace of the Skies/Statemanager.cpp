#pragma once
#include "Statemanager.h"

Engine::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false)
{
}

Engine::StateManager::~StateManager()
{
}

void Engine::StateManager::Add(std::unique_ptr<State> toAdd, bool replace)
{
	m_add = true;
	m_newState = std::move(toAdd);

	m_replace = replace;
}

void Engine::StateManager::PopCurrent()
{
	m_remove = true;

}

void Engine::StateManager::ProcessStateChanges()
{
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
			m_add = false;
	}
}	
	

std::unique_ptr<Engine::State>& Engine::StateManager::getCurrent()
{
	return m_stateStack.top();
}
