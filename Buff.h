#pragma once
#include "entity.h"

struct Effect
{
	int type;
	int id;

	int linearVel;
	int jumpForce;
};

class Buff : public Entity
{
public:
	Buff(b2World* world, sf::RenderWindow* win);
	~Buff();

	void render();

	void createEffect(int id);
	Effect getEffect(){return m_effect;}

	void pick(){m_picked = true;}
	bool isPicked(){return m_picked;}

private:
	b2CircleShape m_box;

	Effect m_effect;

	bool m_picked;
};

