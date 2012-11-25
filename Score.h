#pragma once
#include <SFML\Graphics.hpp>

class Score
{
public:
	Score(void);

	void update();
	void render(sf::RenderWindow* win);
	
	
	int left, right;

private:
	sf::Text m_scoreText;
	
};

