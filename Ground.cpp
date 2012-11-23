#include "Ground.h"


Ground::Ground(b2Vec2 pos, int type, b2World* world, sf::RenderWindow* win) : Entity(world, win, type)
{
	// Ground
	b2BodyDef m_groundBodyDef;
	m_groundBodyDef.type = b2_staticBody;
	m_groundBodyDef.position.Set(pos.x, pos.y);
	m_body = m_world->CreateBody(&m_groundBodyDef);

	m_rBox.SetAsBox(10.0f, 1.0f);
	
	b2FixtureDef m_groundFixtureDef;
	m_groundFixtureDef.shape = &m_rBox;
	m_groundFixtureDef.density = 1.0f;
	m_groundFixtureDef.friction = 0.3f;
	m_groundFixtureDef.filter.groupIndex = -8;
	m_body->CreateFixture(&m_groundFixtureDef);

	m_body->SetUserData(this);

	m_shape.setSize(sf::Vector2f(20*MTP, 2*MTP));
	m_shape.setOrigin(10*MTP, 1.0*MTP);
	m_shape.setFillColor(sf::Color(0, 150, 0));
	
	m_shape.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
}