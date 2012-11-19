#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#define MTP 40

class Player
{
	private:
		b2World* m_world;
		sf::RenderWindow* m_win;

		b2Body* m_body;
		b2BodyDef m_bodyDef;
		b2PolygonShape m_dynamicBox;
		b2FixtureDef m_fixtureDef;

		sf::RectangleShape m_shape;

		int m_vel;

	public:
		Player(b2Vec2(pos), b2World* world, sf::RenderWindow* win);

		void update();
		void handleInput(sf::Event* event);
		void render();
};

