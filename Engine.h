#pragma once
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#include "Player.h"
#include "Ball.h"

#define MTP 40

class Engine
{
	private:
		sf::RenderWindow* m_win;
		b2World* m_world;
		b2Vec2 m_gravity;
		float32 timeStep;

		// Player
		Player* m_player;
		Ball* m_ball;

		// Ground
		b2Body* m_groundBody;
		b2BodyDef m_groundBodyDef;
		b2PolygonShape m_groundBox;
		b2FixtureDef m_groundFixtureDef;
		sf::RectangleShape m_groundShape;

		//£añcuch xD
		b2Body* m_chain;

		sf::Vector2i m_mPos;
		sf::Vector2f m_mGPos;


	public:
		Engine(int w, int h, int bpp = 32);

		void run();

		void input();
		void update(sf::Time dt);
		void render();
};