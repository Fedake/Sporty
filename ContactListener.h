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

		//check if fixture A was player
		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
			if (static_cast<Entity*>(bodyUserData1)->getType() == 1)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					if (static_cast<Entity*>(bodyUserData2)->getType() == 3)
					{
						static_cast<Player*>(bodyUserData1)->startStanding();
					}
				}
			}
		}

		//check if fixture A was ground
		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
			if (static_cast<Entity*>(bodyUserData1)->getType() == 3)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					if (static_cast<Entity*>(bodyUserData2)->getType() == 1)
					{
						static_cast<Player*>(bodyUserData2)->startStanding();
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
					if (static_cast<Entity*>(bodyUserData2)->getType() == 3)
					{
						static_cast<Player*>(bodyUserData1)->endStanding();
					}
				}
			}
		}

		//check if fixture A was ground
		bodyUserData1 = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData1)
		{
			if (static_cast<Entity*>(bodyUserData1)->getType() == 3)
			{
				bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
				if (bodyUserData2)
				{
					if (static_cast<Entity*>(bodyUserData2)->getType() == 1)
					{
						static_cast<Player*>(bodyUserData2)->endStanding();
					}
				}
			}
		}
	}
};