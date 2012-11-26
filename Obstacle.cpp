#include "Obstacle.h"


Obstacle::Obstacle(b2World* world, sf::RenderWindow* win, b2Vec2 pos, float radius) : Entity(world, win, 5)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_staticBody;
	m_bodyDef.position = pos;
	m_body = m_world->CreateBody(&m_bodyDef);

	m_circle.m_radius = radius;
	
	/*b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_circle;
	m_fixtureDef.density = 7.0f;
	m_fixtureDef.friction = 0.3f;
	m_fixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	m_fixtureDef.filter.maskBits = MASK_PLAYER;*/
	m_body->CreateFixture(&m_circle, 0);

	m_circleShape.setOrigin(radius*MTP, radius*MTP);
	m_circleShape.setRadius(radius*MTP);
	m_circleShape.setFillColor(sf::Color::Black);
	m_circleShape.setPosition(pos.x*MTP, pos.y*MTP);

	m_type = 0;
}

Obstacle::Obstacle(b2World* world, sf::RenderWindow* win, b2Vec2 pos, b2Vec2 size, float angle) : Entity(world, win, 5)
{
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_staticBody;
	m_bodyDef.position.Set(pos.x, pos.y);
	m_body = m_world->CreateBody(&m_bodyDef);

	m_box.SetAsBox((size.x/2), (size.y/2), b2Vec2(0, 0), angle*DTR);
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_box;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);

	m_body->SetUserData(this);

	m_boxShape.setSize(sf::Vector2f(size.x*MTP, size.y*MTP));
	m_boxShape.setOrigin((size.x/2)*MTP, (size.y/2)*MTP);
	m_boxShape.setFillColor(sf::Color::Black);
	m_boxShape.setRotation(angle);
	m_boxShape.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);

	m_type = 1;
}

void Obstacle::render()
{
	if(m_type == 0)
	{
		m_win->draw(m_circleShape);
	}
	else if(m_type == 1)
	{
		m_win->draw(m_boxShape);
	}
}