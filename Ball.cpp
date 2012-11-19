#include "Ball.h"


Ball::Ball(b2Vec2(pos), b2World* world, sf::RenderWindow* win) : m_world(world), m_win(win)
{
	// Body
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(3.0f, 0.0f);
	m_body = m_world->CreateBody(&m_bodyDef);

	m_dynamicBox.m_radius = 0.3f;
	
	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);

	m_shape.setRadius(0.3*MTP);
	m_shape.setOrigin(0.3*MTP, 0.3*MTP);
	m_shape.setFillColor(sf::Color::Yellow);
}

void Ball::render()
{
	m_shape.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
	m_win->draw(m_shape);
}