#pragma once

#include <vector>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Buff.h"
#include "ResourceManager.h"
#include "Effect.h"

class BuffManager
{
	private:
		b2World* m_world;
		sf::RenderWindow* m_win;

		ResourceManager* m_resMgr;

		std::vector<Buff*> m_buffs;

		sf::Clock m_time;
	public:
		BuffManager(b2World* world, sf::RenderWindow* win);

		void addBuff(Buff* buff);
		void reset();
		void update();
		void render();
};