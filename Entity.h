#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "Definitions.h"

#define MTP 40
#define RTD 180/b2_pi
#define DTR b2_pi/180

enum Category
{
	CATEGORY_PLAYER = 1,
	CATEGORY_BALL = 2,
	CATEGORY_GROUND = 4,
	CATEGORY_CROSSBAR = 8,
	CATEGORY_LEG = 16,
	CATEGORY_GOAL = 32,
	CATEGORY_BUFF = 64
};

enum Mask
{
	MASK_PLAYER = CATEGORY_GROUND | CATEGORY_CROSSBAR | CATEGORY_BALL | CATEGORY_PLAYER,
	MASK_BALL = CATEGORY_GROUND | CATEGORY_CROSSBAR | CATEGORY_PLAYER | CATEGORY_GOAL | CATEGORY_BUFF,
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

		virtual void setPos(b2Vec2 pos){m_body->SetTransform(pos, m_body->GetAngle()); m_body->SetLinearVelocity(b2Vec2(0, 0));}

		b2Body* getBody() { return m_body; }
};