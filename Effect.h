#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Player.h"

enum BuffCategory
{
	C_SPEED = 0,
	C_JUMP = 1
};

enum BuffType
{
	T_DEBUFF = 0,
	T_NEUTRAL = 1,
	T_BUFF = 2,
};

class Effect
{
	private:
		Player* m_playerL;
		Player* m_playerR;

		int m_type;
		int m_category;
		int m_effect;
		int m_target;
		int m_duration;
		sf::Clock m_time;
	public:
		Effect(int type, int category, int effect, int target, Player* playerL, Player* playerR);
		~Effect();

		Player* getPlayer(int facing) 
		{ 
			if (facing == -1) return m_playerR; 
			else return m_playerL;
		}

		int getType() { return m_type; }
		int getTimeLeft() { return m_duration - m_time.getElapsedTime().asSeconds(); }
};

