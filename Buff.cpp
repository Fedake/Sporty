#include "Buff.h"
#include "ResourceManager.h"


Buff::Buff(b2World* world, sf::RenderWindow* win, BuffEffect effect) 
								: Entity(world, win, effect.type), m_effect(effect)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.gravityScale = 0.0f;
	m_bodyDef.position.Set((rand()%200)/10.f, rand()%100/10.f);
	m_body = m_world->CreateBody(&m_bodyDef);
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_box;
	m_fixtureDef.density = 0.4f;
	m_fixtureDef.friction = 0.3f;

	m_box.m_radius = 0.5f;

	m_fixtureDef.filter.categoryBits = CATEGORY_BUFF;
	m_body->CreateFixture(&m_fixtureDef);
	
	m_body->SetUserData(this);

	m_sprite.setOrigin(0.5*MTP, 0.5*MTP);
	m_sprite.setTexture(*ResourceManager::get()->getBuffTex(m_type));

	m_picked = false;
	m_duration = rand() % 35 + 5;
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