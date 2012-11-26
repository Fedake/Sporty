#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "Entity.h"
#include "ResourceManager.h"

enum BuffType
{
	B_FREEZE = 0,
	B_SLOWSPEED = 1,
	B_SUPERSPEED = 2,
	B_LOWJUMP = 3
};

class Buff : public Entity
{
	private:
		sf::Clock* existTime;
	public:
		Buff(b2World* world, sf::RenderWindow* win, int type);
		~Buff();

		b2CircleShape m_box;

		void render();
};

