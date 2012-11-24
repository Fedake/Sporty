#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Player.h"
#include "Ground.h"
#include "Goal.h"
#include "Ball.h"
#include "ContactListener.h"

class Level
{
	private:
		sf::RenderWindow* m_win;

		b2World* m_world;
		b2Vec2 m_gravity;
		float32 timeStep;

		Player* m_playerL;
		Player* m_playerR;
		Ball* m_ball;
		Ground* m_ground;
		Goal* m_goal[2];
		
		SportowyContactListener contactListener;

		//�a�cuch xD
		b2Body* m_chain;

		sf::Vector2i m_mPos;
		sf::Vector2f m_mGPos;

	public:
		Level(sf::RenderWindow* win);

		int handleInput(sf::Event* ev);
		void update();
		void render();

		void cleanUp();
};

