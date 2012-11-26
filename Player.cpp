#include "Player.h"
#include "ResourceManager.h"

Player::Player(b2Vec2 pos, int facing, int type, b2World* world, sf::RenderWindow* win) : Entity(world, win, type), m_facing(facing)
{
	// Body
	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position = pos;
	m_bodyDef.fixedRotation = true;
	m_body = m_world->CreateBody(&m_bodyDef);

	m_box.m_radius = 0.55f;
	
	b2FixtureDef m_fixtureDef;
	m_fixtureDef.shape = &m_box;
	m_fixtureDef.density = 7.0f;
	m_fixtureDef.friction = 0.1f;
	m_fixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	m_fixtureDef.filter.maskBits = MASK_PLAYER;
	m_body->CreateFixture(&m_fixtureDef);

	m_body->SetUserData(this);

	m_sprite.setOrigin(0.55*MTP, 0.55*MTP);
	m_sprite.setTexture(*ResourceManager::get()->getEntityTex(1));
	m_sprite.setScale((float)-1*m_facing, 1);

	// The leg
	b2BodyDef m_legBodyDef;
	m_legBodyDef.type = b2_dynamicBody;
	m_legBodyDef.gravityScale = 0.0f;
	m_legBodyDef.position.Set(m_body->GetPosition().x, m_body->GetPosition().y+0.7f);

	m_legBody = m_world->CreateBody(&m_legBodyDef);
	m_legBody->SetUserData(this);

	m_legDynamicBox.SetAsBox(0.2f, 0.15f);
	
	b2FixtureDef m_legFixtureDef;
	m_legFixtureDef.shape = &m_legDynamicBox;
	m_legFixtureDef.density = 1.0f;
	m_legFixtureDef.friction = 0.1f;
	m_legFixtureDef.restitution = 1.0f;
	m_legFixtureDef.filter.categoryBits = CATEGORY_LEG;
	m_legFixtureDef.filter.maskBits = MASK_LEG;
	m_legBody->CreateFixture(&m_legFixtureDef);

	m_legSprite.setOrigin(0.2*MTP, 0.15*MTP);
	m_legSprite.setTexture(*ResourceManager::get()->getEntityTex(2));
	m_legSprite.setScale((float)m_facing, 1);

	// Joint
	b2RevoluteJointDef jointDef;
	jointDef.Initialize(m_body, m_legBody, m_body->GetWorldCenter());

	//jointDef.bodyA = m_body;
	//jointDef.bodyB = m_legBody;
	//jointDef.collideConnected = false;
	//jointDef.localAnchorB = m_body->GetWorldCenter();
	jointDef.referenceAngle = 0;
	jointDef.enableLimit = true;

	if(m_facing == 1)
	{
		jointDef.lowerAngle = -100 * b2_pi / 180;
		jointDef.upperAngle = 20 * b2_pi / 180;
	}
	if(m_facing == -1)
	{
		jointDef.lowerAngle = -20 * b2_pi / 180;
		jointDef.upperAngle = 100 * b2_pi / 180;
	}

	jointDef.enableMotor = true;
	jointDef.maxMotorTorque = 10;
	//jointDef.motorSpeed = 60*m_facing * b2_pi / 180;

	m_joint = (b2RevoluteJoint*)m_world->CreateJoint(&jointDef);

	m_kick = false;
	m_vel = 0;
	m_standing = false;
	m_pStanding = false;

	m_speed = 4;
	m_jump = 4;
}

Player::~Player(void)
{
	m_world->DestroyBody(m_body);
	m_world->DestroyJoint(m_joint);
}

void Player::update()
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	float desVel = 0;

	switch (m_vel)
	{
	case -1:
		desVel = b2Max(vel.x - 1.0f, -m_speed); break;
	case 1:
		desVel = b2Min(vel.x + 1.0f, m_speed); break;
	case 0:
		desVel = vel.x * 0.5f; break;
	}
	m_body->SetLinearVelocity(b2Vec2(desVel, vel.y));

	switch (m_kick)
	{
	case 1:
		//m_joint->EnableMotor(true);
		m_joint->SetMotorSpeed(-80.0f*m_facing); break;
	case 0:
		//m_joint->EnableMotor(false);
		m_joint->SetMotorSpeed(10.0f*m_facing); break;
	}
}

void Player::handleInput(sf::Event* event)
{
	if(m_facing == 1)
	{
		if (event->type == sf::Event::KeyPressed)
		{
			if(event->key.code == sf::Keyboard::A) m_vel -= 1;
			if(event->key.code == sf::Keyboard::D)	m_vel += 1;
			if(event->key.code == sf::Keyboard::Space) m_kick = true;
			if(event->key.code == sf::Keyboard::W) 
				if (canJump())
					m_body->ApplyLinearImpulse(b2Vec2(0, -(m_body->GetMass()*m_jump)) , m_body->GetWorldCenter());
		}
		if (event->type == sf::Event::KeyReleased)
		{

			if(event->key.code == sf::Keyboard::A) m_vel += 1;
			if(event->key.code == sf::Keyboard::D)	m_vel -= 1;
			if(event->key.code == sf::Keyboard::Space) m_kick = false;
		}
	}
	if(m_facing == -1)
	{
		if (event->type == sf::Event::KeyPressed)
		{
			if(event->key.code == sf::Keyboard::Left) m_vel -= 1;
			if(event->key.code == sf::Keyboard::Right)	m_vel += 1;
			if(event->key.code == sf::Keyboard::P) m_kick = true;
			if(event->key.code == sf::Keyboard::Up) 
				if (canJump()) m_body->ApplyLinearImpulse(b2Vec2(0, -(m_body->GetMass()*m_jump)), m_body->GetWorldCenter());
		}
		if (event->type == sf::Event::KeyReleased)
		{
			if(event->key.code == sf::Keyboard::Left) m_vel += 1;
			if(event->key.code == sf::Keyboard::Right)	m_vel -= 1;
			if(event->key.code == sf::Keyboard::P) m_kick = false;
		}
	}
}

void Player::render()
{
	m_sprite.setPosition(m_body->GetPosition().x*MTP, m_body->GetPosition().y*MTP);

	m_legSprite.setPosition(m_legBody->GetPosition().x*MTP, m_legBody->GetPosition().y*MTP);
	m_legSprite.setRotation(180*m_legBody->GetAngle()/b2_pi);
	m_win->draw(m_sprite);
	m_win->draw(m_legSprite);
}