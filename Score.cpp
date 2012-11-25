#include "Score.h"
#include <sstream>

Score::Score(void)
{
	m_scoreText.setCharacterSize(60);
	m_font.loadFromFile("data/font.ttf");
	m_scoreText.setFont(m_font);
	m_scoreText.setColor(sf::Color::Black);
}

void Score::update()
{
	std::stringstream s;

	s << left << ":" << right;

	m_scoreText.setString(s.str());
	m_scoreText.setOrigin(m_scoreText.getLocalBounds().width/2, 0);
	m_scoreText.setPosition(400, 100);
}

void Score::render(sf::RenderWindow* win)
{
	win->draw(m_scoreText);
}