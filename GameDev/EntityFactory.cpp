#include "EntityFactory.h"


EntityFactory::EntityFactory(b2World& b2world) : world(b2world)
{
	entityRegistery =	std::unordered_map<EntityType, Entity*>{
			{ EntityType::ENTITY,new Entity() },
			{ EntityType::ACTOR, new Actor() },
			{ EntityType::NPC, new Npc() },
			{ EntityType::PLAYER, new Player() }
	};
	b2BodyDef entDef = b2BodyDef();
	entDef.type = b2BodyType::b2_staticBody;
	b2BodyDef ActorDef;
	ActorDef.type = b2BodyType::b2_dynamicBody;
	b2BodyDef NpcDef;
	NpcDef.type = b2BodyType::b2_dynamicBody;
	b2BodyDef PlayerDef;
	PlayerDef.type = b2BodyType::b2_dynamicBody;

	bodyRegistery = std::unordered_map<EntityType, b2BodyDef>{
			{ EntityType::ENTITY,  entDef },
			{ EntityType::ACTOR,  ActorDef },
			{ EntityType::NPC,  NpcDef },
			{ EntityType::PLAYER,  PlayerDef }
	};

}

EntityFactory::~EntityFactory()
{
	for (auto it = entityRegistery.begin(); it != entityRegistery.end(); ++it){
		delete it->second;
	}

	
	
}

Entity* EntityFactory::CreateEntity(float x, float y,float height, float width, EntityType type)
{
	Entity* ent = entityRegistery.at(type)->EmptyClone();

	ent->Init(CreateBody(x, y,height,width, type),width,height);
	return ent;

}
b2Body* EntityFactory::CreateBody(float x, float y,float height,float width, EntityType type)
{
	
	b2PolygonShape boxShape;
	boxShape.SetAsBox(height, width);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	




	b2BodyDef bodydef = bodyRegistery.at(type);	
	bodydef.position.Set(x, y);
	b2Body* b2body = world.CreateBody(&bodydef);
	b2body->CreateFixture(&boxFixtureDef);
	return b2body;

}
