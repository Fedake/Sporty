#pragma once
#include "Entity.h"

class Goal : public Entity
{
public:
	Goal(b2Vec2 pos, int facing, int type, b2World* world, sf::RenderWindow* win);

	int getFacing() { return m_facing; }
private:
	b2PolygonShape m_box;
	b2PolygonShape m_goalBox;

	int m_facing;
};

