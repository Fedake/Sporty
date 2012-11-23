#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <math.h>
#include <iostream>

#include "Entity.h"

class Player : public Entity
{
	private:
		// Leg
		b2Body* m_legBody;
		b2PolygonShape m_legDynamicBox;
		sf::Sprite m_legSprite;

		// Joint
		b2RevoluteJointDef m_jointDef;
		b2RevoluteJoint* m_joint;

		// Velocity
		int m_vel;
		bool m_kick;

		int m_facing;

		bool m_standing;

	public:
		Player(b2Vec2 pos, int facing, int type, b2World* world, sf::RenderWindow* win);

		void update();
		void handleInput(sf::Event* event);
		void render();

		void startStanding() { m_standing = true; }
		void endStanding() { m_standing = false; }
};

