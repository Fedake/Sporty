#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#define MTP 40

class Entity
{
	protected:
		b2World* m_world;
		sf::RenderWindow* m_win;

		// Body
		b2Body* m_body;
		b2PolygonShape m_rBox;
		b2CircleShape m_cBox;
		b2Vec2 m_pos;

		sf::RectangleShape m_shape;
		sf::Sprite m_sprite;


		int m_type;
	public:
		Entity(b2World* world, sf::RenderWindow* win, int type);
		virtual void render();


};