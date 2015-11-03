#pragma once
#include "Entity.h"
#include "EntityType.h"
#include <iostream>
#include <unordered_map>
#include "Actor.h"
#include "Npc.h"
#include "Player.h"

class EntityFactory
{
public:
	EntityFactory(b2World& world);
	~EntityFactory();
	Entity* CreateEntity(float x, float y, float height, float width, EntityType type);
	b2Body* CreateBody(float x, float y, float height, float width, EntityType type);

private:


	std::unordered_map<EntityType,Entity*> entityRegistery;
	std::unordered_map<EntityType, b2BodyDef > bodyRegistery;
	b2World& world;

};

