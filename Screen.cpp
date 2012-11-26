#include "Screen.h"
Screen* Screen::m_instance = NULL;

Screen::Screen(void)
{
	m_dt.restart();
	m_text.setCharacterSize(50);
	m_text.setFont(*ResourceManager::get()->getDefaultFont());
}

Screen* Screen::get()
{
	if(m_instance == NULL) m_instance = new Screen();
	return m_instance;
}

void Screen::update()
{
	if(m_strings.size() > 0)
	{
		m_strings.front().delay -= m_dt.getElapsedTime().asMilliseconds();
		if(m_strings.front().delay < 0) m_strings.erase(m_strings.begin());
		else
		{
			m_text.setString(m_strings.front().str);
			m_text.setPosition(m_strings.front().centerPos.x - m_text.getLocalBounds().width/2, m_strings.front().centerPos.y - m_text.getLocalBounds().height/2);
			m_text.setColor(m_strings.front().color);
		}
	}
	m_dt.restart();
}
void Screen::render(sf::RenderWindow* win)
{
	if(m_strings.size() > 0) win->draw(m_text);
}
	
void Screen::print(std::string text, int delay, sf::Vector2f centerPos, sf::Color color)
{
	ScreenString n;
	n.str = text;
	n.delay = delay;
	n.centerPos = centerPos;
	n.color = color;

	m_strings.push_back(n);
}