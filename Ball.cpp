#include "Ball.h"

#include <iostream>

Ball::Ball(b2Vec2 pos, int type, b2World* world, sf::RenderWindow* win) : Entity(world, win, type)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(6.0f, 1.0f);
	m_bodyDef.linearDamping = 0.3;
	m_bodyDef.bullet = true;
	m_body = m_world->CreateBody(&m_bodyDef);
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_cBox;
	m_fixtureDef.density = 0.4f;
	m_fixtureDef.friction = 0.3f;

	m_cBox.m_radius = 0.25f;

	m_fixtureDef.density = 0.4f;
	m_fixtureDef.friction = 0.5f;
	m_fixtureDef.restitution = 0.6f;
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