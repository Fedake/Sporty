#include "ResourceManager.h"
ResourceManager* ResourceManager::m_instance = NULL;

ResourceManager::ResourceManager()
{
	m_entTex.push_back(new sf::Texture());
	m_entTex[0]->loadFromFile("data/tex/ball.png");
	m_entTex[0]->setSmooth(true);
}

ResourceManager* ResourceManager::get()
{
	if(m_instance == NULL) m_instance = new ResourceManager();
	return m_instance;
}