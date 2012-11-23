#pragma once

#include <Box2D\Box2D.h>
#include <iostream>
#include "Player.h"
#include "Engine.h"

class SportowyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact)
	{
	}

    void EndContact(b2Contact* contact)
	{
	}
};