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
		b2CircleShape m_dynamicBox;
		sf::Sprite m_sprite;
		
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

	public:
		Player(b2Vec2 pos, int facing, b2World* world, sf::RenderWindow* win);

		void update();
		void handleInput(sf::Event* event);
		void render();
};

