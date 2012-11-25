#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"

class DebugInfo
{
public:
	DebugInfo();

	void update(int dt, Entity* p1, Entity* p2, Entity* ball, int);
	void render(sf::RenderWindow* win);

	void toggle(){m_active = !m_active;}
	 
private:
	sf::Text m_debugText;

	bool m_active;
};

