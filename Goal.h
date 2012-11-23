#pragma once
#include "Entity.h"

class Goal : public Entity
{
public:
	Goal(b2Vec2 pos, int facing, b2World* world, sf::RenderWindow* win);

private:
	int m_facing;
};

