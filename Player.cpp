#include "Player.h"


Player::Player(b2Vec2 pos, b2World* world, sf::RenderWindow* win) : m_world(world), m_win(win)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(5.0f, 5.0f);
	m_bodyDef.fixedRotation = true;
	m_body = m_world->CreateBody(&m_bodyDef);

	m_dynamicBox.m_radius = 0.5f;
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 4.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);

	m_shape.setRadius(0.5*MTP);
	m_shape.setOrigin(0.5*MTP, 0.5*MTP);
	m_shape.setFillColor(sf::Color::Red);

	// The leg
	b2BodyDef m_legBodyDef;
	m_legBodyDef.type = b2_dynamicBody;
	m_legBodyDef.gravityScale = 0.0f;
	m_legBodyDef.position.Set(m_body->GetPosition().x, m_body->GetPosition().y+0.6f);

	m_legBody = m_world->CreateBody(&m_legBodyDef);

	m_legDynamicBox.SetAsBox(0.15f, 0.2f);
	
	b2FixtureDef m_legFixtureDef;
	m_legFixtureDef.shape = &m_legDynamicBox;
	m_legFixtureDef.density = 1.0f;
	m_legFixtureDef.friction = 0.1f;
	m_legFixtureDef.restitution = 2.0f;
	m_legFixtureDef.filter.groupIndex = -8;
	m_legBody->CreateFixture(&m_legFixtureDef);

	m_legShape.setSize(sf::Vector2f(0.3*MTP, 0.4*MTP));
	m_legShape.setOrigin(0.15*MTP, 0.2*MTP);
	m_legShape.setFillColor(sf::Color::Red);

	// Joint
	b2RevoluteJointDef jointDef;
	jointDef.Initialize(m_body, m_legBody, m_body->GetWorldCenter());

	//jointDef.bodyA = m_body;
	//jointDef.bodyB = m_legBody;
	//jointDef.collideConnected = false;
	//jointDef.localAnchorB = m_body->GetWorldCenter();
	jointDef.referenceAngle = 0;
	jointDef.enableLimit = true;
	jointDef.lowerAngle = -100 * b2_pi / 180;
	jointDef.upperAngle = 20 * b2_pi / 180;
	jointDef.enableMotor = true;
	jointDef.maxMotorTorque = 8;
	jointDef.motorSpeed = 60 * b2_pi / 180;

	m_joint = (b2RevoluteJoint*)m_world->CreateJoint(&jointDef);

	m_kick = false;
	m_vel = 0;
}

void Player::update()
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	float force = 0;

	switch (m_vel)
	{
	case -1:
		if (vel.x > -4) force = -80; break;
	case 1:
		if (vel.x < 4) force =  80; break;
	case 0:
		force = vel.x * -10; break;
	}
	m_body->ApplyForce(b2Vec2(force, 0), m_body->GetWorldCenter());

	switch (m_kick)
	{
	case 1:
		//m_joint->EnableMotor(true);
		m_joint->SetMotorSpeed(-60.0f); break;
	case 0:
		//m_joint->EnableMotor(false);
		m_joint->SetMotorSpeed(40.0f); break;
	}
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
		case sf::Keyboard::Space:
			m_kick = true; break;
		case sf::Keyboard::Up:
			m_body->ApplyLinearImpulse(b2Vec2(0, -12), m_body->GetWorldCenter());
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
		case sf::Keyboard::Space:
			m_kick = false; break;
		}
	}
}

void Player::render()
{
	m_shape.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);
	m_legShape.setPosition(m_legBody->GetPosition().x*MTP, m_legBody->GetPosition().y*MTP);
	m_legShape.setRotation(180*m_legBody->GetAngle()/b2_pi);
	m_win->draw(m_shape);
	m_win->draw(m_legShape);
}