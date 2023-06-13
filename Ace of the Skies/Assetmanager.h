#pragma once
#include<map>
#include<memory>
#include<string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
namespace Engine
{
	class Assetmanager
	{
	private:
		std::map<int, std::unique_ptr<sf::Texture>>m_textures;
		std::map<int, std::unique_ptr<sf::Font>>m_fonts;
	public:
		Assetmanager();
		~Assetmanager();

		void AddTexture(int id,const std::string& filepath, bool isReapeted=false);
		void AddFont(int id, const std::string& filepath);
		

		const sf::Texture& GetTexture(int id) const;
		const sf::Font& GetFont(int id) const;
	
	};
}


