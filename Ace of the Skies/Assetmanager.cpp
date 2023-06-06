#include "Assetmanager.h"

Engine::Assetmanager::Assetmanager()
{
}

Engine::Assetmanager::~Assetmanager()
{
}

void Engine::Assetmanager::AddTexture(int id, const std::string& filepath, bool isReapeted)
{
	auto texture = std::make_unique<sf::Texture>();

	if (texture->loadFromFile(filepath))
	{
		texture->setRepeated(isReapeted);
		m_textures[id] = std::move(texture);
	}
}

void Engine::Assetmanager::AddFont(int id, const std::string& filepath)
{
	auto font = std::make_unique<sf::Font>();

	if (font->loadFromFile(filepath))
	{
		m_fonts[id] = std::move(font);
	}
}

const sf::Texture& Engine::Assetmanager::GetTexture(int id) const
{
	return *(m_textures.at(id).get());
}
const sf::Font& Engine::Assetmanager::GetFont(int id) const
{
	return *(m_fonts.at(id).get());
}
