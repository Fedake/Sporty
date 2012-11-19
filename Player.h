#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <math.h>
#include <iostream>

#define MTP 40

class Player
{
	private:
		b2World* m_world;
		sf::RenderWindow* m_win;

		// Body
		b2Body* m_body;
		b2BodyDef m_bodyDef;
		b2CircleShape m_dynamicBox;
		b2FixtureDef m_fixtureDef;
		sf::CircleShape m_shape;
		
		// Leg
		b2Body* m_legBody;
		b2BodyDef m_legBodyDef;
		b2PolygonShape m_legDynamicBox;
		b2FixtureDef m_legFixtureDef;
		sf::RectangleShape m_legShape;

		// Joint
		b2RevoluteJointDef m_jointDef;
		b2RevoluteJoint* m_joint;

		// Velocity
		int m_vel;
		bool m_kick;

	public:
		Player(b2Vec2(pos), b2World* world, sf::RenderWindow* win);

		void update();
		void handleInput(sf::Event* event);
		void render();
};

