#include "DebugInfo.h"
#include <sstream>
#include "ResourceManager.h"

DebugInfo::DebugInfo(void) : m_active(false)
{
	m_debugText.setCharacterSize(15);
	m_debugText.setColor(sf::Color::Black);
	m_debugText.setFont(*ResourceManager::get()->getDefaultFont());
}

void DebugInfo::update(int dt, Entity* p1, Entity* p2, Entity* ball, int bodies)
{
	if(m_active)
	{
		std::stringstream s;
		s <<
		"Fps: " << 1000000.f/dt << "\n" <<
		"P1 x: " << p1->getPos().x << " y: " << p1->getPos().y << "\n" <<
		"P2 x: " << p2->getPos().x << " y: " << p2->getPos().y << "\n" <<
		"Ball x: " << ball->getPos().x << " y: " << ball->getPos().y << "\n" << 
		"Bodies count: " << bodies << "\n";

		m_debugText.setString(s.str());
	}
}

void DebugInfo::render(sf::RenderWindow* win)
{
	if(m_active) win->draw(m_debugText);
}