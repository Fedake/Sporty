#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#include "ResourceManager.h"
#include "Entity.h"

class Ball : public Entity
{
	private:
		b2CircleShape m_box;
		bool m_onGoal;
		int m_dir;

		int m_owner;

	public:
		Ball(b2Vec2 pos, int type, b2World* world, sf::RenderWindow* win);
		~Ball(void);

		void render();
		void update();

		void onGoal(bool state) { m_onGoal = state; }
		void onGoal(bool state, int dir) { m_onGoal = state; m_dir = dir; }

		void setOwner(int owner){m_owner = owner;}
		int getOwner(){return m_owner;}
};

