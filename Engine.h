#pragma once
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#define MTP 40

class Engine
{
	private:
		sf::RenderWindow* m_win;
		b2World* m_world;
		b2Vec2 m_gravity;
		float32 timeStep;

		// Body
		b2Body* m_body;
		b2BodyDef m_bodyDef;
		b2PolygonShape m_dynamicBox;
		b2FixtureDef m_fixtureDef;
		sf::RectangleShape m_shape;

		// Ground
		b2Body* m_groundBody;
		b2BodyDef m_groundBodyDef;
		b2PolygonShape m_groundBox;
		b2FixtureDef m_groundFixtureDef;
		sf::RectangleShape m_groundShape;

		sf::Vector2i m_mPos;
		sf::Vector2f m_mGPos;

		sf::Text m_info;

	public:
		Engine(int w, int h, int bpp = 32);

		void run();

		void input();
		void update(sf::Time dt);
		void render();
};