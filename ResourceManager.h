#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ResourceManager
{
	public:
		sf::Texture* getEntityTex(int n){return m_entTex[n];}

		static ResourceManager* get();

	private:
		ResourceManager();
		static ResourceManager* m_instance;

		std::vector<sf::Texture*> m_entTex;



};