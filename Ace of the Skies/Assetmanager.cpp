#include "Assetmanager.h"
#include <iostream>

Engine::Assetmanager::Assetmanager()
{//konstruktor
}

Engine::Assetmanager::~Assetmanager()
{//destruktor
}

void Engine::Assetmanager::AddTexture(int id, const std::string& filepath, bool isReapeted)
{	// Tworzenie unikalnego wskaünika do tekstury
	auto texture = std::make_unique<sf::Texture>();

	if (texture->loadFromFile(filepath))
	{
		texture->setRepeated(isReapeted);
		// Dodawanie tekstury do mapy tekstur
		m_textures[id] = std::move(texture);
	}
	else
	{
		std::cout << "nie  udalo sie wczytac "<<filepath << std::endl;
	}
}

void Engine::Assetmanager::AddFont(int id, const std::string& filepath)
{	// Tworzenie unikalnego wskaünika do czcionki
	auto font = std::make_unique<sf::Font>();

	if (font->loadFromFile(filepath))
	{	// Dodawanie czcionki do mapy czcionek
		m_fonts[id] = std::move(font);
	}
}



const sf::Texture& Engine::Assetmanager::GetTexture(int id) const
{	// Pobieranie tekstury o danym identyfikatorze
	return *(m_textures.at(id).get());
}
const sf::Font& Engine::Assetmanager::GetFont(int id) const
{	// Pobieranie czcionki o danym identyfikatorze
	return *(m_fonts.at(id).get());
}


