#pragma once

#include <Box2D\Box2D.h>

#include "Entity.h"

class Ground : public Entity
{
	public:
		Ground(b2Vec2 pos, int type, b2World* world, sf::RenderWindow* win);
};

