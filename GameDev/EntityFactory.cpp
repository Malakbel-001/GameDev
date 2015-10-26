#include "EntityFactory.h"


EntityFactory::EntityFactory(b2World& b2world) : world(b2world)
{
	registery =	std::unordered_map<EntityType, Entity>{
			{ EntityType::ENTITY, Entity() },
			{ EntityType::ACTOR, Actor() },
			{ EntityType::NPC, Npc() },
			{ EntityType::PLAYER, Player() }
	};

}

EntityFactory::~EntityFactory()
{

}

Entity* EntityFactory::CreateEntity(float x, float y, EntityType type)
{
	Entity* ent = registery.at(type).EmptyClone();
	b2BodyDef bodydef;
	bodydef.position.Set(x, y);
	b2Body* b2body = world.CreateBody(&bodydef);
	ent->Init(b2body);
	return ent;

}
