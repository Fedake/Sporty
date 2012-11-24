#include "Buff.h"
#include "ResourceManager.h"

Buff::Buff(b2World* world, sf::RenderWindow* win) : Entity(world, win, 90)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.active = false;
	m_bodyDef.position.Set((rand()%200)/10.f, (rand()%100)/10.f);
	m_body = m_world->CreateBody(&m_bodyDef);
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_box;
	m_fixtureDef.density = 0.4f;
	m_fixtureDef.friction = 0.3f;

	m_box.m_radius = 0.25f;

	m_fixtureDef.filter.categoryBits = CATEGORY_BALL;
	m_body->CreateFixture(&m_fixtureDef);
	
	m_body->SetUserData(this);
	
	m_sprite.setOrigin(0.25*MTP, 0.25*MTP);
	m_sprite.setTexture(*ResourceManager::get()->getEntityTex(0));
}

Buff::~Buff()
{
	m_world->DestroyBody(m_body);
}


void Buff::render()
{
	m_sprite.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);

	m_win->draw(m_sprite);
}