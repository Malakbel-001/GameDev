
#include "EntityFactory.h"



EntityFactory::EntityFactory(b2World& b2world, BehaviourFactory* _bf, DrawableContainer* _drawContainer) : world(b2world), bf(_bf), drawContainer(_drawContainer)
{

	actorRegistery = std::unordered_map<EntityType, Actor*>{
			{ EntityType::ACTOR, new Actor() },
			{ EntityType::NPC, new Npc() },
			{ EntityType::PLAYER, new Player() },
			{ EntityType::PLANT, new Npc() },
			{ EntityType::BULLET, new Bullet() },
	};
	entityRegistery = std::unordered_map<EntityType, Entity*>{
		{ EntityType::ENTITY, new Entity() },	
		{ EntityType::GROUND, new Ground() },
		{ EntityType::GROUND2, new Ground() },
		{ EntityType::BAR, new Ground() },
		
	};
	b2BodyDef entDef = b2BodyDef();
	entDef.type = b2BodyType::b2_staticBody;
	entDef.fixedRotation = true;
	b2BodyDef ActorDef;
	ActorDef.type = b2BodyType::b2_dynamicBody;
	b2BodyDef NpcDef;
	NpcDef.type = b2BodyType::b2_dynamicBody;
	b2BodyDef PlayerDef;
	PlayerDef.gravityScale = 1;
	PlayerDef.fixedRotation = true;
	PlayerDef.linearDamping = 0.5f;
	PlayerDef.angularDamping = 1;
	PlayerDef.type = b2BodyType::b2_dynamicBody;

	b2BodyDef PlantDef = b2BodyDef();
	PlantDef.gravityScale = 1;
	PlantDef.fixedRotation = true;
	PlantDef.linearDamping = 0.5f;
	PlantDef.angularDamping = 1;
	PlantDef.type = b2BodyType::b2_dynamicBody;


	b2BodyDef Bullet = b2BodyDef();
	Bullet.gravityScale = 0;
	Bullet.fixedRotation = true;
	Bullet.linearDamping = 0;
	Bullet.angularDamping = 0;
	Bullet.type = b2BodyType::b2_dynamicBody;
	Bullet.bullet = true;
	


	bodyRegistery = std::unordered_map<EntityType, b2BodyDef>{
		{ EntityType::ENTITY, entDef },
		{ EntityType::ACTOR, ActorDef },
		{ EntityType::NPC, NpcDef },
		{ EntityType::PLAYER, PlayerDef },
		{ EntityType::PLANT, PlantDef },
		{ EntityType::GROUND, entDef },
		{ EntityType::GROUND2, entDef },
		{ EntityType::BAR, entDef },
		{EntityType::BULLET,Bullet}
	};

}

EntityFactory::~EntityFactory()
{
	for (auto it = entityRegistery.begin(); it != entityRegistery.end(); ++it)
	{
		delete it->second;
	}
}

Entity* EntityFactory::CreateEntity(float x, float y, float height, float width, EntityType type)
{
	Entity* ent = entityRegistery.at(type)->EmptyClone();
	b2Body* body = CreateBody(x, y, height, width, type);
	
	ent->Init(body, width, height, type, bf, drawContainer);


	return ent;
}
Actor* EntityFactory::CreateActor(int _hitdmg,int _healt, float x, float y, float height, float width, EntityType type){
	Actor* ent = actorRegistery.at(type)->EmptyClone();
	b2Body* body = CreateBody(x, y, height, width, type);	
	ent->InitActor(body, _hitdmg, _healt, width, height, type, bf, drawContainer);


	return ent;
}
b2Body* EntityFactory::CreateBody(float x, float y, float height, float width, EntityType type)
{

	b2PolygonShape boxShape;
	//transalte pixels -> units

	height = height / 2;
	width = width / 2;
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;
	float newHeight = (height*Ratio);
	float newWidth = (width*Ratio);
	boxShape.SetAsBox(newHeight, newWidth, b2Vec2(newHeight, newWidth), 0);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;

	boxFixtureDef.density = 1;





	b2BodyDef bodydef = bodyRegistery.at(type);
	bodydef.position.Set(x*Ratio, y*Ratio);
	b2Body* b2body = world.CreateBody(&bodydef);
	b2body->CreateFixture(&boxFixtureDef);
	b2body->SetTransform(b2Vec2(x*Ratio, y*Ratio), 0);
	
	return b2body;

}