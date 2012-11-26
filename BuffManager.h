#pragma once

#include <vector>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Buff.h"
#include "ResourceManager.h"
#include "Effect.h"
#include "Player.h"

#define EFFECT_COUNT 2

class BuffManager
{
	private:
		b2World* m_world;
		sf::RenderWindow* m_win;
		Player* m_playerL;
		Player* m_playerR;

		ResourceManager* m_resMgr;

		std::vector<Buff*> m_buffs;
		Effect* m_effects[2][EFFECT_COUNT];

		sf::Clock m_time;
	public:
		BuffManager(b2World* world, sf::RenderWindow* win, Player* playerL, Player* playerR);

		void addBuff(Buff* buff);
		void reset();
		void update();
		void render();
		void setEffect(Buff* buff, int target);
};