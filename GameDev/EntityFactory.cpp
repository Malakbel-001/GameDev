#include "EntityFactory.h"


EntityFactory::EntityFactory(b2World& b2world) : world(b2world)
{
	registery =	std::unordered_map<EntityType, Entity>{
			{ EntityType::ENTITY, Entity() },
			{ EntityType::ACTOR, Actor() },
			{ EntityType::NPC, Npc() },
			{ EntityType::PLAYER, Player() },
			{ EntityType::GROUND, Ground() }
	};

}

EntityFactory::~EntityFactory()
{

}

Entity* EntityFactory::CreateEntity(float x, float y, EntityType type)
{

	Entity* ent = registery.at(type).EmptyClone();

	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	myBodyDef.position.Set(100, 20); //set the starting position
	myBodyDef.angle = 0; //set the starting angle

	
	

	// Add the ground fixture to the ground body.

	b2Body* b2body = world.CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(15, 15);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	b2body->CreateFixture(&boxFixtureDef);

	ent->Init(b2body);
	return ent;

}
Entity* EntityFactory::CreateStaticEntity(float x, float y, EntityType type)
{
	
	Entity* ent = registery.at(type).EmptyClone();
	b2BodyDef bodydef;
	bodydef.type = b2BodyType::b2_staticBody;
	
	bodydef.position.Set(x, y);


	// Add the ground fixture to the ground body.

	b2Body* b2body = world.CreateBody(&bodydef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(15, 15);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	b2body->CreateFixture(&boxFixtureDef);


	
	ent->Init(b2body);
	return ent;

}
