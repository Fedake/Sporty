#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Player.h"
#include "Ground.h"
#include "Goal.h"
#include "Ball.h"
#include "Score.h"

#include "BuffManager.h"

#include "DebugInfo.h"

class SportowyContactListener;

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

		Score m_score;
		bool m_scored;

		BuffManager* m_buffMgr;

		DebugInfo* m_dbg;
		
		SportowyContactListener* contactListener;

		//£añcuch xD
		b2Body* m_chain;

		sf::Vector2i m_mPos;
		sf::Vector2f m_mGPos;

		sf::Clock m_dt;

	public:
		Level(sf::RenderWindow* win);

		int handleInput(sf::Event* ev);
		void update();
		void render();

		void score(int goal);
		void reset();

		void applyEffect(Effect effect, int ballOwner);

		void cleanUp();
};

