#pragma once

#include <Box2D\Box2D.h>
#include <iostream>
#include "Player.h"
#include "Ground.h"
#include "Entity.h"
#include "Level.h"

#include "Definitions.h"

class SportowyContactListener : public b2ContactListener
{
public:
	SportowyContactListener(Level* level) : m_level(level){}
private:
	Level* m_level;

	

	void BeginContact(b2Contact* contact)
	{
		void* bodyUserData1;
		void* bodyUserData2;

		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
///////////////////////////////////////////// JUMPING ////////////////////////////////////////////////
			// check if fixture A was player
			if (static_cast<Entity*>(bodyUserData1)->getType() == 1)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was ground start standing
					if (static_cast<Entity*>(bodyUserData2)->getType() == 3)
					{
						static_cast<Player*>(bodyUserData1)->startStanding();
					}
				
					// if fixture B was another player
					if (static_cast<Entity*>(bodyUserData2)->getType() == 1)
					{
						b2Vec2 pos1 = static_cast<Player*>(bodyUserData1)->getPos();
						b2Vec2 pos2 = static_cast<Player*>(bodyUserData2)->getPos();

						// if player1 is higher than player2
						if (pos1.y < pos2.y - 0.5f)
						{
							static_cast<Player*>(bodyUserData1)->startPStanding();
						}
						// if player2 is higher than player1
						if (pos2.y < pos1.y - 0.5f)
						{
							static_cast<Player*>(bodyUserData2)->startPStanding();
						}
					}
				}
			}
			// check if fixture A was ground
			if (static_cast<Entity*>(bodyUserData1)->getType() == 3)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was player start standing
					if (static_cast<Entity*>(bodyUserData2)->getType() == 1)
					{
						static_cast<Player*>(bodyUserData2)->startStanding();
					}
				}
			}

/////////////////////////////////////////// BALL ON GOAL /////////////////////////////////////////////////
			// check if fixture A was ball
			if (static_cast<Entity*>(bodyUserData1)->getType() == 2)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was goal apply force
					if (static_cast<Entity*>(bodyUserData2)->getType() == 4)
					{
						Ball* ball = static_cast<Ball*>(bodyUserData1);
						Goal* goal = static_cast<Goal*>(bodyUserData2);
						ball->onGoal(true, goal->getFacing());
					}
				}
			}
			// check if fixture A was goal
			if (static_cast<Entity*>(bodyUserData1)->getType() == 4)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was ball apply force
					if (static_cast<Entity*>(bodyUserData2)->getType() == 2)
					{
						Ball* ball = static_cast<Ball*>(bodyUserData2);
						Goal* goal = static_cast<Goal*>(bodyUserData1);
						ball->onGoal(true, goal->getFacing());
					}
				}
			}
		}
	}

    void EndContact(b2Contact* contact)
	{
		void* bodyUserData1;
		void* bodyUserData2;

		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
///////////////////////////////////////////// JUMPING ////////////////////////////////////////////////
			//check if fixture A was player
			if (static_cast<Entity*>(bodyUserData1)->getType() == 1)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was ground start standing
					if (static_cast<Entity*>(bodyUserData2)->getType() == 3)
					{
						static_cast<Player*>(bodyUserData1)->endStanding();
					}
				
					// if fixture B was another player
					else if (static_cast<Entity*>(bodyUserData2)->getType() == 1)
					{
						Player* player1 = static_cast<Player*>(bodyUserData1);
						Player* player2 = static_cast<Player*>(bodyUserData2);

						// if player1 is not on the ground start player-standing
						if (!player1->isStanding()) player1->endPStanding();
						// if player2 is not on the ground start player-standing
						if (!player2->isStanding()) player2->endPStanding();
					}
				}
			}
			// check if fixture A was ground
			if (static_cast<Entity*>(bodyUserData1)->getType() == 3)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was player start standing
					if (static_cast<Entity*>(bodyUserData2)->getType() == 1)
					{
						static_cast<Player*>(bodyUserData2)->endStanding();
					}
				}
			}

/////////////////////////////////////////// BALL ON GOAL /////////////////////////////////////////////////
			// check if fixture A was ball
			if (static_cast<Entity*>(bodyUserData1)->getType() == 2)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was goal apply force
					if (static_cast<Entity*>(bodyUserData2)->getType() == 4)
					{
						Ball* ball = static_cast<Ball*>(bodyUserData1);
						Goal* goal = static_cast<Goal*>(bodyUserData2);
						ball->onGoal(false);
					}
				}
			}
			// check if fixture A was goal
			if (static_cast<Entity*>(bodyUserData1)->getType() == 4)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					// if fixture B was ball apply force
					if (static_cast<Entity*>(bodyUserData2)->getType() == 2)
					{
						Ball* ball = static_cast<Ball*>(bodyUserData2);
						Goal* goal = static_cast<Goal*>(bodyUserData1);
						ball->onGoal(false);
					}
				}
			}

////////////////////////////////////SET BALL'S OWNER///////////////////////////////////////
			if (static_cast<Entity*>(bodyUserData1)->getType() == E_BALL)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2 && static_cast<Entity*>(bodyUserData2)->getType() == E_PLAYER)
				{
					Ball* ball = static_cast<Ball*>(bodyUserData1);
					Player* player = static_cast<Player*>(bodyUserData2);

					ball->setOwner(player->getFacing());
				}
			}

			if (static_cast<Entity*>(bodyUserData1)->getType() == E_PLAYER)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2 && static_cast<Entity*>(bodyUserData2)->getType() == E_BALL)
				{
					Ball* ball = static_cast<Ball*>(bodyUserData2);
					Player* player = static_cast<Player*>(bodyUserData1);

					ball->setOwner(player->getFacing());
				}
			}

		}
	}

	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
	{
		void* bodyData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		void* bodyData2 = contact->GetFixtureB()->GetBody()->GetUserData();
		//GOALS
		if (contact->GetFixtureA()->GetFilterData().categoryBits == CATEGORY_GOAL)
		{
      		contact->SetEnabled(false);
			if(static_cast<Entity*>(bodyData2)->getType() == E_BALL)
			{
				Goal* goal = static_cast<Goal*>(bodyData1);
				Ball* ball = static_cast<Ball*>(bodyData2);
				m_level->score(goal->getFacing());
			}
		}
		if (contact->GetFixtureB()->GetFilterData().categoryBits == CATEGORY_GOAL)
		{
      		contact->SetEnabled(false);
			if(static_cast<Entity*>(bodyData1)->getType() == E_BALL)
			{
				Goal* goal = static_cast<Goal*>(bodyData2);
				Ball* ball = static_cast<Ball*>(bodyData1);
				m_level->score(goal->getFacing());
			}
		}

		//BUFFS
		/*
		if (contact->GetFixtureA()->GetFilterData().categoryBits == CATEGORY_BUFF)
		{
      		contact->SetEnabled(false);
			if(contact->GetFixtureB()->GetFilterData().categoryBits == CATEGORY_BALL)
			{
				Buff* buff = static_cast<Buff*>(bodyData1);
				Ball* ball = static_cast<Ball*>(bodyData2);

				m_level->applyEffect(buff->getEffect(), ball->getOwner());
				buff->pick();
			}
		}
		if (contact->GetFixtureB()->GetFilterData().categoryBits == CATEGORY_BUFF)
		{
      		contact->SetEnabled(false);
			if(contact->GetFixtureA()->GetFilterData().categoryBits == CATEGORY_BALL)
			{
				Buff* buff = static_cast<Buff*>(bodyData2);
				Ball* ball = static_cast<Ball*>(bodyData1);

				m_level->applyEffect(buff->getEffect(), ball->getOwner());
				buff->pick();
			}
		}
		*/
	}
};