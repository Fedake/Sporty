#include "Player.h"


Player::Player(b2Vec2(pos), b2World* world, sf::RenderWindow* win) : m_world(world), m_win(win)
{
	// Body
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(1.0f, 0.0f);
	m_bodyDef.fixedRotation = true;
	m_body = m_world->CreateBody(&m_bodyDef);

	m_dynamicBox.m_radius = 1.0f;
	
	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);

	m_shape.setRadius(1*MTP);
	m_shape.setOrigin(1*MTP, 1*MTP);
	m_shape.setFillColor(sf::Color::Red);

	// The leg
	m_legBodyDef.type = b2_dynamicBody;
	m_legBodyDef.position.Set(3.0f, 0.0f);
	m_legBodyDef.angle = 0.8f;
	m_legBody = m_world->CreateBody(&m_legBodyDef);

	m_legDynamicBox.SetAsBox(0.2f, 0.4f);

	m_legFixtureDef.shape = &m_legDynamicBox;
	m_legFixtureDef.density = 1.0f;
	m_legFixtureDef.friction = 0.3f;
	m_legBody->CreateFixture(&m_legFixtureDef);

	m_legShape.setSize(sf::Vector2f(0.4*MTP, 0.8*MTP));
	m_legShape.setOrigin(0.2*MTP, 0.4*MTP);
	m_legShape.setFillColor(sf::Color::Red);

	m_vel = 0;
}

void Player::update()
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	float force = 0;

	switch (m_vel)
	{
	case -1:
		if (vel.x > -5) force = -50; break;
	case 1:
		if (vel.x < 5) force =  50; break;
	case 0:
		force = vel.x * -10; break;
	}
	m_body->ApplyForce(b2Vec2(force, 0), m_body->GetWorldCenter());
}

void Player::handleInput(sf::Event* event)
{
	if (event->type == sf::Event::KeyPressed)
	{
		switch(event->key.code)
		{
		case sf::Keyboard::Left:
			m_vel -= 1; break;
		case sf::Keyboard::Right:
			m_vel += 1; break;
		}
	}
	if (event->type == sf::Event::KeyReleased)
	{
		switch(event->key.code)
		{
		case sf::Keyboard::Left:
			m_vel += 1; break;
		case sf::Keyboard::Right:
			m_vel -= 1; break;
		}
	}
}

void Player::render()
{
	m_shape.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
	m_legShape.setPosition(m_legBody->GetPosition().x*MTP, m_legBody->GetPosition().y*MTP);
	m_legShape.setRotation(180*m_legBody->GetAngle()/3.14);
	m_win->draw(m_shape);
	m_win->draw(m_legShape);
}