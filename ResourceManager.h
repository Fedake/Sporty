#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ResourceManager
{
	public:
		sf::Texture* getEntityTex(int n){return m_entTex[n];}
		sf::Texture* getBuffTex(int n){return m_buffTex[n];}
		sf::Font* getDefaultFont(){return m_font;}

		static ResourceManager* get();

	private:
		ResourceManager();
		static ResourceManager* m_instance;

		std::vector<sf::Texture*> m_entTex;
		std::vector<sf::Texture*> m_buffTex;

		sf::Font* m_font;



};