#include "Engine.h"
#include <sstream>

Engine::Engine(int w, int h, int bpp)
{
	//Graphics
	sf::ContextSettings conSet = sf::ContextSettings();
	conSet.antialiasingLevel = 4;
	
	m_win = new sf::RenderWindow(sf::VideoMode(w, h, bpp), "Solar System", sf::Style::Default, conSet);
	m_win->setFramerateLimit(60);
	m_win->setKeyRepeatEnabled(false);

	m_info.setCharacterSize(15);

	m_gravity.Set(0, 10);
	m_world = new b2World(m_gravity);

	// Body
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(1.0f, 0.0f);
	m_body = m_world->CreateBody(&m_bodyDef);

	m_dynamicBox.SetAsBox(1.0f, 1.0f);
	
	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);

	m_shape.setSize(sf::Vector2f(1*MTP, 1*MTP));
	m_shape.setOrigin(0.5*MTP, 0.5*MTP);
	m_shape.setFillColor(sf::Color::Red);

	// Ground
	m_groundBodyDef.type = b2_staticBody;
	m_groundBodyDef.position.Set(5.0f, 15.0f);
	m_groundBody = m_world->CreateBody(&m_groundBodyDef);

	m_groundBox.SetAsBox(10.0f, 1.0f);

	m_groundFixtureDef.shape = &m_groundBox;
	m_groundFixtureDef.density = 1.0f;
	m_groundFixtureDef.friction = 0.3f;
	m_groundBody->CreateFixture(&m_groundFixtureDef);

	m_groundShape.setSize(sf::Vector2f(10*MTP, 1*MTP));
	m_groundShape.setOrigin(5*MTP, 0.5*MTP);
	m_groundShape.setFillColor(sf::Color::Blue);
	
	m_groundShape.setPosition(m_groundBody->GetPosition().x*MTP, m_groundBody->GetPosition().y*MTP);


	// Step
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
	m_shape.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);

	std::stringstream s;
	s <<
	"Fps: " << 1000000.f/dt.asMicroseconds() << "\n";

	m_info.setString(s.str());
}

void Engine::render()
{
	m_win->clear(sf::Color::Black);

	m_win->draw(m_shape);
	m_win->draw(m_groundShape);
	m_win->draw(m_info);

	m_win->display();
}