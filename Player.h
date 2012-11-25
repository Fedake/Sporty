#pragma once

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <math.h>
#include <iostream>

#include "Entity.h"
#include "EffectManager.h"

class Player : public Entity
{
	private:
		// Leg
		b2Body* m_legBody;
		b2CircleShape m_box;
		b2PolygonShape m_legDynamicBox;
		sf::Sprite m_legSprite;

		// Joint
		b2RevoluteJointDef m_jointDef;
		b2RevoluteJoint* m_joint;

		EffectManager m_eMgr;

		// Velocity
		int m_vel;
		bool m_kick;

		int m_facing;

		bool m_standing;
		bool m_pStanding;

	public:
		Player(b2Vec2 pos, int facing, int type, b2World* world, sf::RenderWindow* win);
		~Player(void);

		void update();
		void handleInput(sf::Event* event);
		void render();

		void startStanding() { m_standing = true; }
		void endStanding() { m_standing = false; }

		void startPStanding() { m_pStanding = true; }
		void endPStanding() { m_pStanding = false; }

		void setPos(b2Vec2 pos){m_body->SetTransform(pos, m_body->GetAngle()); m_legBody->SetTransform(pos + b2Vec2(0, 0.7f), m_body->GetAngle());}

		bool isStanding() { return m_standing; }
		bool canJump() { return m_standing || m_pStanding;	}

		int getFacing(){return m_facing;}

		void addEffect(Effect e){m_eMgr.addEffect(e);}
};

