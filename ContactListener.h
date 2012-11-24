#pragma once

#include <Box2D\Box2D.h>
#include <iostream>
#include "Player.h"
#include "Ground.h"
#include "Entity.h"

class SportowyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact)
	{
		void* bodyUserData1;
		void* bodyUserData2;

		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
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
		}
	
		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
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

		//check if fixture A was player
		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
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
			
		}
	
		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
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
		}
	}
};