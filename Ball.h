#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#define MTP 40

class Ball
{
	private:
		b2World* m_world;
		sf::RenderWindow* m_win;

		// Body
		b2Body* m_body;
		b2CircleShape m_dynamicBox;

		sf::Sprite m_sprite;

	public:
		Ball(b2Vec2 pos, b2World* world, sf::RenderWindow* win);
		~Ball(void);

		void render();
};

