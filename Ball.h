#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#define MTP 40

class Ball
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
	public:
		Ball(b2Vec2(pos), b2World* world, sf::RenderWindow* win);
		~Ball(void);

		void render();
};

