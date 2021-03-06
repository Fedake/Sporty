#include "Ball.h"

#include <iostream>

Ball::Ball(b2Vec2 pos, int type, b2World* world, sf::RenderWindow* win) : Entity(world, win, type), m_owner(0)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position = pos;
	m_bodyDef.linearDamping = 0.3f;
	m_bodyDef.bullet = true;
	m_body = m_world->CreateBody(&m_bodyDef);
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_box;
	m_fixtureDef.density = 0.4f;
	m_fixtureDef.friction = 0.3f;

	m_box.m_radius = 0.25f;

	m_fixtureDef.density = 0.4f;
	m_fixtureDef.friction = 0.5f;
	m_fixtureDef.restitution = 0.6f;
	m_fixtureDef.filter.categoryBits = CATEGORY_BALL;
	m_body->CreateFixture(&m_fixtureDef);
	
	m_body->SetUserData(this);
	
	m_sprite.setOrigin(0.25*MTP, 0.25*MTP);
	m_sprite.setTexture(*ResourceManager::get()->getEntityTex(0));

	m_onGoal = false;
}

void Ball::render()
{
	m_sprite.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
	m_sprite.setRotation(m_body->GetAngle()*180/3.141);

	m_win->draw(m_sprite);
}

void Ball::update()
{
	if (m_onGoal)
	{
		m_body->ApplyForce(b2Vec2(0.1f*m_dir, 0), m_body->GetWorldCenter());
	}
}