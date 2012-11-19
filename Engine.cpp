#include "Engine.h"
#include <sstream>

Engine::Engine(int w, int h, int bpp)
{
	//Graphics
	sf::ContextSettings conSet = sf::ContextSettings();
	conSet.antialiasingLevel = 4;
	
	m_win = new sf::RenderWindow(sf::VideoMode(w, h, bpp), "Solar System", sf::Style::Titlebar, conSet);
	m_win->setFramerateLimit(60);
	m_win->setKeyRepeatEnabled(false);

	m_info.setCharacterSize(15);

	m_shape.setSize(sf::Vector2f(20, 20));
	m_shape.setOrigin(10, 10);
	m_shape.setFillColor(sf::Color::Red);

	//Physics
	m_gravity.Set(0, 10);
	m_world = new b2World(m_gravity);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(20.0f, 0.0f);
	m_box = m_world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.5f, 0.5f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	m_box->CreateFixture(&fixtureDef);

	timeStep = 1.0f / 60.0f;
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
		if(ev.type == sf::Event::Closed) m_win->close();
		if(ev.type == sf::Event::KeyPressed)
		{
		}
		if(ev.type == sf::Event::KeyReleased)
		{
		}

		if(ev.type == sf::Event::MouseWheelMoved)
		{
		}
		if(ev.type == sf::Event::MouseButtonPressed)
		{

		}
		if(ev.type == sf::Event::MouseMoved)
		{
			m_mPos.x = ev.mouseMove.x;
			m_mPos.y = ev.mouseMove.y;
		}
	}
}

void Engine::update(sf::Time dt)
{
	m_world->Step(timeStep, 6, 2);
	m_shape.setPosition(m_box->GetPosition().x*20, m_box->GetPosition().y*20);

	std::stringstream s;
	s <<
	"Fps: " << 1000000.f/dt.asMicroseconds() << "\n";

	m_info.setString(s.str());
}

void Engine::render()
{
	m_win->clear(sf::Color::Black);

	m_win->draw(m_shape);
	m_win->draw(m_info);

	m_win->display();
}