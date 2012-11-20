#include "Ball.h"
#include "ResourceManager.h"

Ball::Ball(b2Vec2 pos, b2World* world, sf::RenderWindow* win) : m_world(world), m_win(win)
{
	// Body
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(3.0f, 0.0f);
	m_body = m_world->CreateBody(&m_bodyDef);

	m_dynamicBox.m_radius = 0.25f;
	
	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 0.5f;
	m_fixtureDef.friction = 0.3f;
	m_fixtureDef.restitution = 0.5f;
	m_body->CreateFixture(&m_fixtureDef);

	m_sprite.setOrigin(0.25*MTP, 0.25*MTP);
	m_sprite.setTexture(*ResourceManager::get()->getEntityTex(0));
}

void Ball::render()
{
	m_sprite.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
	m_sprite.setRotation(m_body->GetAngle()*180/3.141);

	m_win->draw(m_sprite);
}