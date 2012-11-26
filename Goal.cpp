#include "Goal.h"
#include "ResourceManager.h"

Goal::Goal(b2Vec2 pos, int facing, int type, b2World* world, sf::RenderWindow* win) : Entity(world, win, type), m_facing(facing)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(pos.x, pos.y);
	m_body = m_world->CreateBody(&bodyDef);

	m_box.SetAsBox(0.75f, 0.1f);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &m_box;
	fixtureDef.friction = 0.3f;
	fixtureDef.filter.categoryBits = CATEGORY_CROSSBAR;
	m_body->CreateFixture(&fixtureDef);

	m_goalBox.SetAsBox(0.50f, 1.5f, b2Vec2(0, 1.60f), 0);

	b2FixtureDef goalFixtureDef;
	goalFixtureDef.shape = &m_goalBox;
	goalFixtureDef.friction = 0.3f;
	goalFixtureDef.filter.categoryBits = CATEGORY_GOAL;
	m_body->CreateFixture(&goalFixtureDef);

	m_body->SetUserData(this);

	m_sprite.setTexture(*ResourceManager::get()->getEntityTex(3));
	m_sprite.setScale(m_facing, 1);
	m_sprite.setOrigin(0.75*MTP, 0.1*MTP);
	
	m_sprite.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
}
