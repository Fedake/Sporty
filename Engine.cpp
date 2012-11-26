#include "Engine.h"
#include <sstream>

Engine::Engine(int w, int h, int bpp)
{
	srand(time(NULL));

	// Graphics
	sf::ContextSettings conSet = sf::ContextSettings();
	conSet.antialiasingLevel = 4;
	
	m_win = new sf::RenderWindow(sf::VideoMode(w, h, bpp), "Sporty", sf::Style::Default, conSet);
	m_win->setFramerateLimit(60);
	m_win->setKeyRepeatEnabled(false);
	
	// Level
	m_level = new Level(m_win);

	srand(static_cast<unsigned>(time(NULL)));
}

void Engine::run()
{
	sf::Clock delta;

	delta.restart();
	while(m_win->isOpen())
	{
		if (input() == 1) break;
		update(delta.getElapsedTime());
		delta.restart();
		render();
	}
}

int Engine::input()
{
	sf::Event ev;
	while (m_win->pollEvent(ev))
	{
		if (m_level->handleInput(&ev) == 1) return 1;
	}
	return 0;
}

void Engine::update(sf::Time dt)
{
	m_level->update();
}

void Engine::render()
{
	m_win->clear(sf::Color(111, 188, 204));

	m_level->render();

	m_win->display();
}