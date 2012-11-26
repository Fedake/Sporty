#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Player.h"
#include "Ground.h"
#include "Goal.h"
#include "Ball.h"
#include "Score.h"
#include "Obstacle.h"
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
		int m_goalDelay;
		int m_resetDelay;

		DebugInfo* m_dbg;
		
		SportowyContactListener* contactListener;

		BuffManager* m_buffMgr;

		std::vector<Obstacle*> m_obstacles;

		b2Vec2 m_ballStartPos;

		//£añcuch xD
		b2Body* m_chain;

		sf::Vector2i m_mPos;
		sf::Vector2f m_mGPos;

		sf::Clock m_dt;

	public:
		Level(sf::RenderWindow* win);

		void loadLevel(std::string path);

		int handleInput(sf::Event* ev);
		void update();
		void render();

		void score(int goal);
		void reset();

		Player* getPlayer(int facing) 
		{ 
			if (facing == -1) return m_playerR; 
			if (facing == 1) return m_playerL;
		}

		BuffManager* getBuffManager() { return m_buffMgr; }

		void cleanUp();
};

