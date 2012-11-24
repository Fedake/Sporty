#include "Level.h"


Level::Level(sf::RenderWindow* win) : m_win(win)
{
	m_gravity.Set(0, 8);
	m_world = new b2World(m_gravity);

	m_ground = new Ground(b2Vec2(10.0f, 14.0f), 3, m_world, m_win);
	m_playerL = new Player(b2Vec2(2.0f, 2.0f), 1, 1, m_world, m_win);
	m_playerR = new Player(b2Vec2(10.0f, 2.0f), -1, 1, m_world, m_win);

	
	m_ball = new Ball(b2Vec2(3.0f, 0.0f), 2, m_world, m_win);

	m_goal[0] = new Goal(b2Vec2(0.75f, 10.6f), 1, m_world, m_win);
	m_goal[1] = new Goal(b2Vec2(19.25f, 10.6f), -1, m_world, m_win);

	m_world->SetContactListener(&contactListener);

	// World endings
	b2BodyDef chainDef;
	chainDef.type = b2_staticBody;
	chainDef.position.Set(0, 0);

	m_chain = m_world->CreateBody(&chainDef);

	b2Vec2 verts[4];
	verts[0].Set(0, 0);
	verts[1].Set(20, 0);
	verts[2].Set(20, 15);
	verts[3].Set(0, 15);
	b2ChainShape chainShape;
	chainShape.CreateLoop(verts, 4);

	m_chain->CreateFixture(&chainShape, 0.0f);

	// Step
	timeStep = 1.0f / 60.0f;
}

int Level::handleInput(sf::Event* ev)
{
	m_playerL->handleInput(ev);
	m_playerR->handleInput(ev);		
	if(ev->type == sf::Event::Closed)
	{
		cleanUp();
		m_win->close();
		return 1;
	}
	if(ev->type == sf::Event::KeyPressed)
	{
	}
	if(ev->type == sf::Event::KeyReleased)
	{
	}

	if(ev->type == sf::Event::MouseWheelMoved)
	{
	}
	if(ev->type == sf::Event::MouseButtonPressed)
	{

	}
	if(ev->type == sf::Event::MouseMoved)
	{
		m_mPos.x = ev->mouseMove.x;
		m_mPos.y = ev->mouseMove.y;
	}
	return 0;
}

void Level::update()
{
	m_playerL->update();
	m_playerR->update();

	m_world->Step(timeStep, 6, 2);
}

void Level::render()
{
	m_ground->render();
	m_playerL->render();
	m_playerR->render();

	m_ball->render();

	m_goal[0]->render();
	m_goal[1]->render();
}

void Level::cleanUp()
{
	delete m_world;

	m_playerL = NULL;
	m_playerR = NULL;
	m_ball = NULL;
	m_ground = NULL;
	m_goal[0] = NULL;
	m_goal[1] = NULL;
	m_chain = NULL;
}