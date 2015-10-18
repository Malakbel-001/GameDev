#include "Level.h"


Level::Level()
{
	world = new b2World(b2Vec2(0.0, 9.81));
}

b2World* Level::GetWorld(){
	return world;
}

Level::~Level()
{
}
