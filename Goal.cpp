#include "Goal.h"
#include "ResourceManager.h"

Goal::Goal(b2Vec2 pos, int facing, b2World* world, sf::RenderWindow* win) : Entity(world, win, 3), m_facing(facing)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(pos.x, pos.y);
	m_body = m_world->CreateBody(&bodyDef);

	m_rBox.SetAsBox(0.75, 0.1);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &m_rBox;
	fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&fixtureDef);

	m_sprite.setTexture(*ResourceManager::get()->getEntityTex(3));
	m_sprite.setScale(m_facing, 1);
	m_sprite.setOrigin(0.75*MTP, 0.1*MTP);
	
	m_sprite.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
}
