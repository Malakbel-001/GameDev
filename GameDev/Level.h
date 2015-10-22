#pragma once
#include "Box2D\Box2D.h"
class Level
{
public:
	Level();

	virtual ~Level();

	b2World* GetWorld();

private:
	
	b2World* world;

};

