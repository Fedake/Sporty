#pragma once
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#include "Entity.h"
#include "Player.h"
#include "Ball.h"
#include "Ground.h"
#include "ContactListener.h"
#include "Goal.h"

#define MTP 40

class Engine
{
	private:
		sf::RenderWindow* m_win;
		b2World* m_world;
		b2Vec2 m_gravity;
		float32 timeStep;

		// Player
		Player* m_playerL;
		Player* m_playerR;
		Ball* m_ball;
		Ground* m_ground;
		Goal* m_goal[2];


		SportowyContactListener contactListener;

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