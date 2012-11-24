#include "Engine.h"
#include <sstream>

Engine::Engine(int w, int h, int bpp)
{
	// Graphics
	sf::ContextSettings conSet = sf::ContextSettings();
	conSet.antialiasingLevel = 4;
	
	m_win = new sf::RenderWindow(sf::VideoMode(w, h, bpp), "Sporty", sf::Style::Default, conSet);
	m_win->setFramerateLimit(60);
	m_win->setKeyRepeatEnabled(false);

	// Level
	m_level = new Level(m_win);
}

void Engine::run()
{
	sf::Clock delta;

	delta.restart();
	while(m_win->isOpen())
	{
		input();
		update(delta.getElapsedTime());
		delta.restart();
		render();
	}
}

void Engine::input()
{
	sf::Event ev;
	while (m_win->pollEvent(ev))
	{
		m_level->handleInput(&ev);
	}
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