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
		std::map<int, std::unique_ptr<sf::Texture>> m_textures; // Mapa przechowujπca wskaüniki na tekstury
		std::map<int, std::unique_ptr<sf::Font>> m_fonts; // Mapa przechowujπca wskaüniki na czcionki
	public:
		//konstruktor destruktor
		Assetmanager();
		~Assetmanager();

		void AddTexture(int id,const std::string& filepath, bool isReapeted=false);// Dodawanie tekstury do mapy
		void AddFont(int id, const std::string& filepath);// Dodawanie czcionki do mapy

		const sf::Texture& GetTexture(int id) const;//pobieranie tekstury o danym id
		const sf::Font& GetFont(int id) const;//pobieranie czcionki o danym id
	
	};
}


