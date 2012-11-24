#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#define MTP 40

enum Category
{
	CATEGORY_PLAYER = 0x0001,
	CATEGORY_BALL = 0x0002,
	CATEGORY_GROUND = 0x0004,
	CATEGORY_CROSSBAR = 0x0008,
	CATEGORY_LEG = 0x0016,
	CATEGORY_GOAL = 0x0032
};

enum Mask
{
	MASK_PLAYER = CATEGORY_GROUND | CATEGORY_CROSSBAR | CATEGORY_BALL | CATEGORY_PLAYER,
	MASK_BALL = CATEGORY_GROUND | CATEGORY_CROSSBAR | CATEGORY_PLAYER,
	MASK_GROUND = CATEGORY_PLAYER | CATEGORY_BALL,
	MASK_CROSSBAR = CATEGORY_PLAYER | CATEGORY_BALL,
	MASK_LEG = CATEGORY_CROSSBAR | CATEGORY_BALL | CATEGORY_PLAYER,
	MASK_GOAL = CATEGORY_GROUND
};

class Entity
{
	protected:
		b2World* m_world;
		sf::RenderWindow* m_win;

		// Body
		b2Body* m_body;

		sf::RectangleShape m_shape;
		sf::Sprite m_sprite;


		int m_type;
	public:
		Entity(b2World* world, sf::RenderWindow* win, int type);
		virtual void render();

		int getType() { return m_type; }
		b2Vec2 getPos() { return m_body->GetPosition(); }

		b2Body* getBody() { return m_body; }
};