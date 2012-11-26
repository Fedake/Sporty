#pragma once
#include <SFML\Graphics.hpp>
#include "ResourceManager.h"

struct ScreenString
{
	std::string str;
	float delay;

	sf::Vector2f centerPos;
	sf::Color color;
};

class Screen
{
private:
	Screen(void);
	static Screen* m_instance;

	sf::Text m_text;
	std::vector<ScreenString> m_strings;
	sf::Clock m_dt;

public:
	static Screen* get();
	
	void update();
	void render(sf::RenderWindow* win);
	
	void print(std::string text, int delay = 1000, sf::Vector2f centerPos = sf::Vector2f(400, 300), sf::Color color = sf::Color::Black);

};

