#pragma once
#include "entity.h"
class Buff : public Entity
{
public:
	Buff(b2World* world, sf::RenderWindow* win);
	~Buff();

	void render();

private:
	b2CircleShape m_box;
};

