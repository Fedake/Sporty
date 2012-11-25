#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ResourceManager
{
	public:
		sf::Texture* getEntityTex(int n){return m_entTex[n];}
		sf::Texture* getBuffTex(int n){return m_buffTex[n+1];}

		static ResourceManager* get();

	private:
		ResourceManager();
		static ResourceManager* m_instance;

		std::vector<sf::Texture*> m_entTex;
		std::vector<sf::Texture*> m_buffTex;



};