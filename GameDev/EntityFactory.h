#pragma once
#include "Entity.h"
#include "Actor.h"
#include "Npc.h"
#include "Player.h"
#include <iostream>
#include <unordered_map>
#include "BehaviourFactory.h"
#include "Ground.h"
#include "Bullet.h"


class EntityFactory
{
public:
	EntityFactory(b2World& world, BehaviourFactory* _bf, DrawableContainer* _drawContainer);
	~EntityFactory();
	Entity* CreateEntity(float x, float y, float height, float width, EntityType type);
	Actor* CreateActor(int _hitdmg, int _healt, float x, float y, float height, float width, EntityType type);

	b2Body* CreateBody(float x, float y, float height, float width, EntityType type);

private:
	DrawableContainer* drawContainer;
	BehaviourFactory* bf;
	std::unordered_map<EntityType,Entity*> entityRegistery;
	std::unordered_map<EntityType, Actor*> actorRegistery;
	std::unordered_map<EntityType, b2BodyDef > bodyRegistery;
	b2World& world;

};

