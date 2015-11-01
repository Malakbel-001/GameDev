#pragma once
#include "Entity.h"
#include "EntityType.h"
#include <iostream>
#include <unordered_map>
#include "Actor.h"
#include "Npc.h"
#include "Player.h"
#include "Ground.h"

class EntityFactory
{
public:
	EntityFactory(b2World& world);
	~EntityFactory();
	Entity* CreateEntity(float x, float y, EntityType type);
	Entity* CreateStaticEntity(float x, float y, EntityType type);

private:


	std::unordered_map<EntityType,Entity> registery;
	b2World& world;

};

