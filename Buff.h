#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Entity.h"
#include "ResourceManager.h"

class BuffEffect
{
	public:
		int type;
		int category;
		int effect;
};

class Buff : public Entity
{
	private:
		sf::Clock m_time;
		BuffEffect m_effect;

		bool m_picked;

		int m_duration;
	public:
		Buff(b2World* world, sf::RenderWindow* win, BuffEffect effect);
		~Buff();

		b2CircleShape m_box;

		void render();
		
		BuffEffect getBuffEffect() { return m_effect; }

		void pick() { m_picked = true; }
		bool isPicked() { return m_picked; }

		int getTimeLeft() { return m_duration - m_time.getElapsedTime().asSeconds(); }
};

