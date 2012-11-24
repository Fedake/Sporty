#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#include "ResourceManager.h"
#include "Entity.h"

class Ball : public Entity
{
	private:
		b2CircleShape m_box;

	public:
		Ball(b2Vec2 pos, int type, b2World* world, sf::RenderWindow* win);
		~Ball(void);

		void render();
};

