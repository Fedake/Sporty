#pragma once
#include "Entity.h"

class Goal : public Entity
{
public:
	Goal(b2Vec2 pos, int facing, b2World* world, sf::RenderWindow* win);

private:
	b2PolygonShape m_box;
	int m_facing;
};

