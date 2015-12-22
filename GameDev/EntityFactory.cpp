
#include "EntityFactory.h"



EntityFactory::EntityFactory(b2World& b2world, std::vector<Actor*>* _actor, std::vector<Entity*>* _ent, BehaviourFactory* _bf, Level* _level, DrawableContainer* _drawContainer, MoveableContainer* _moveContainer) : world(b2world), actor(_actor), bf(_bf), level(_level), drawContainer(_drawContainer), moveContainer(_moveContainer), entities(_ent)
{
	actorRegistery = std::unordered_map<EntityType, Actor*>{
		{ EntityType::ACTOR, new Actor() },
		{ EntityType::TANK, new Vehicle() },
		{ EntityType::MECH, new Vehicle() },
		{ EntityType::NPC, new Npc() },
		{ EntityType::PLAYER, new Player() },
		{ EntityType::PLANT, new Npc() },
		{ EntityType::PLANTBOSS, new Npc() },
		{ EntityType::BULLET, new Bullet() },
		{ EntityType::ACORN, new Acorn() },
		{ EntityType::PINGUIN, new Npc() },
		{ EntityType::HEALTH, new Actor()},
		{ EntityType::AMMO, new Actor() },
		{ EntityType::SNOWMAN, new Npc() },
	};

	entityRegistery = std::unordered_map<EntityType, Entity*>{
		{ EntityType::ENTITY, new Entity() },	
		{ EntityType::GROUND, new Ground() },
		{ EntityType::GROUND2, new Ground() },
		{ EntityType::BAR, new Ground() },

		//level2
		{ EntityType::GROUNDLVL2, new Ground() },

		//level3
		{ EntityType::DESERTFLOOR, new Ground() },
	};

	weaponRegistery = std::unordered_map < EntityType, Weapon* > {
			{ EntityType::WEAPON, new Weapon() },
			{ EntityType::SHOTGUN, new ShotGun() },
	};

	bulletRegistery = std::unordered_map < EntityType, Bullet* > {
			{ EntityType::BULLET ,new Bullet() }

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

	b2BodyDef TankDef;
	TankDef.gravityScale = 1;
	TankDef.fixedRotation = true;
	TankDef.linearDamping = 0.5f;
	TankDef.angularDamping = 1;
	TankDef.type = b2BodyType::b2_dynamicBody;

	b2BodyDef MechDef;
	MechDef.gravityScale = 1;
	MechDef.fixedRotation = true;
	MechDef.linearDamping = 0.5f;
	MechDef.angularDamping = 1;
	MechDef.type = b2BodyType::b2_dynamicBody;

	b2BodyDef PlantDef = b2BodyDef();
	PlantDef.gravityScale = 1;
	PlantDef.fixedRotation = true;
	PlantDef.linearDamping = 0.5f;
	PlantDef.angularDamping = 1;
	PlantDef.type = b2BodyType::b2_dynamicBody;

	b2BodyDef PlantBossDef = b2BodyDef();
	PlantBossDef.gravityScale = 1;
	PlantBossDef.fixedRotation = true;
	PlantBossDef.linearDamping = 0.5f;
	PlantBossDef.angularDamping = 1;
	PlantBossDef.type = b2BodyType::b2_dynamicBody;


	b2BodyDef Bullet = b2BodyDef();
	Bullet.gravityScale = 0.05;
	Bullet.fixedRotation = true;
	Bullet.linearDamping = 0;
	Bullet.angularDamping = 0;
	Bullet.type = b2BodyType::b2_dynamicBody;
	Bullet.bullet = true;
	
	b2BodyDef Health = b2BodyDef();
	Health.gravityScale = 1;
	Health.fixedRotation = false;
	Health.linearDamping = 0.5;
	Health.angularDamping = 1;

	Health.type = b2BodyType::b2_dynamicBody;
	
	b2BodyDef Ammo = b2BodyDef();
	Ammo.gravityScale = 1;
	Ammo.fixedRotation = true;
	Ammo.linearDamping = 0.5;
	Ammo.angularDamping = 1;
	Ammo.type = b2BodyType::b2_dynamicBody;

	
	b2BodyDef AcornDef = b2BodyDef();
	AcornDef.gravityScale = 0.01;
	AcornDef.fixedRotation = true;
	AcornDef.linearDamping = 0;
	AcornDef.angularDamping = 0;
	AcornDef.type = b2BodyType::b2_dynamicBody;
	AcornDef.bullet = true;

	b2BodyDef SnowmanDef = b2BodyDef();
	SnowmanDef.gravityScale = 1;
	SnowmanDef.fixedRotation = true;
	SnowmanDef.linearDamping = 0.5f;
	SnowmanDef.angularDamping = 1;
	SnowmanDef.type = b2BodyType::b2_dynamicBody;

	bodyRegistery = std::unordered_map<EntityType, b2BodyDef>{
		{ EntityType::ENTITY, entDef },
		{ EntityType::ACTOR, ActorDef },
		{ EntityType::NPC, NpcDef },
		{ EntityType::PLAYER, PlayerDef },
		{ EntityType::PLANT, PlantDef },
		{ EntityType::PLANTBOSS, PlantBossDef },
		{ EntityType::GROUND, entDef },
		{ EntityType::GROUND2, entDef },
		{ EntityType::BAR, entDef },

		{ EntityType::BULLET, Bullet },
		{ EntityType::HEALTH, Health },
		{ EntityType::AMMO, Ammo },
		{ EntityType::ACORN, AcornDef },
		
		//level2
		{ EntityType::GROUNDLVL2, entDef },
		{ EntityType::PINGUIN, PlantDef },
		{ EntityType::SNOWMAN, SnowmanDef },

		//level3
		{ EntityType::DESERTFLOOR, entDef },
		{ EntityType::TANK, TankDef },
		{ EntityType::MECH, MechDef },
	};
		npcStatsRegistery = std::unordered_map < EntityType, NpcStatsContainer* > {
			{ EntityType::PLANT, new NpcStatsContainer(25, 50, 100, 40, 45) },
			{ EntityType::PLANTBOSS, new NpcStatsContainer(50, 500, 1000, 100, 100) },
			{ EntityType::PINGUIN, new NpcStatsContainer(34, 75, 200, 24, 36) },
			{ EntityType::SNOWMAN, new NpcStatsContainer(45, 130, 250, 42, 34) },
			{ EntityType::TANK, new NpcStatsContainer(0, 500, 0, 55, 65) },
			{ EntityType::MECH, new NpcStatsContainer(0, 500, 0, 180, 150) },
		};
}

EntityFactory::~EntityFactory()
{
	for (auto it = actorRegistery.begin(); it != actorRegistery.end(); ++it)
	{
		delete it->second;
	}
	
	for (auto it = entityRegistery.begin(); it != entityRegistery.end(); ++it)
	{
		delete it->second;
	}
	for (auto it = weaponRegistery.begin(); it != weaponRegistery.end(); ++it)
	{
		delete it->second;
	}
	for (auto it = bulletRegistery.begin(); it != bulletRegistery.end(); ++it)
	{
		delete it->second;
	}

}

Weapon* EntityFactory::CreateWeapon(float x, float y, EntityType type){
	Weapon* wep = weaponRegistery.at(type)->EmptyClone();
	wep->Init(x, y, 0, EntityState::IDLE, type, bf, drawContainer, moveContainer);
	return wep;
}

Entity* EntityFactory::CreateEntity(float x, float y, float height, float width, EntityType type){
	
	Entity* ent = entityRegistery.at(type)->EmptyClone();
	b2Body* body = CreateBody(x, y, height, width, 1, type);

	ent->Init(body, width, height, type, bf, drawContainer, moveContainer);
	
	entities->push_back(ent);
	ent->SetLevel(level);
	return ent;
}

//temporarily still here
Actor* EntityFactory::CreateActor(int _hitdmg,int _health, float x, float y, float height, float width, EntityType type){
	Actor* ent = actorRegistery.at(type)->EmptyClone();
	b2Body* body = CreateActorBody(x, y, height, width,1, type, ent);
	ent->InitActor(body, _hitdmg, _health, width, height, type, bf, drawContainer, moveContainer);
	actor->push_back(ent);
	ent->SetLevel(level);
	return ent;
}

Actor* EntityFactory::CreateActor(float x, float y, EntityType type) {
	Actor* ent = actorRegistery.at(type)->EmptyClone();
	if (npcStatsRegistery.find(type) == npcStatsRegistery.end()) { //error handling, avoid crashing
		std::cout << "Actor: " << "[insert EntityType here] " << "is not found in the npcStatsRegistery - CreateActor!" << std::endl;
	}
	else {
		NpcStatsContainer* npcStats = npcStatsRegistery.at(type);
		b2Body* body = CreateActorBody(x, y, npcStats->GetHeight(), npcStats->GetWidth(), 1, type, ent);
		ent->InitActor(body, npcStats->GetHitDmg(), npcStats->GetHealth(), npcStats->GetWidth(), npcStats->GetHeight()
			, type, bf, drawContainer, moveContainer);


		ent->SetScore(npcStats->GetScore());
		ent->SetLevel(level);
		ent->SetState(EntityState::IDLE);
		b2Vec2 dir;
		dir.y = 0;
		dir.x = 0;
		ent->SetDirection(dir);
		actor->push_back(ent);
	}

	return ent;
}

Player* EntityFactory::CreatePlayer(int _hitdmg, int _health, float x, float y, float height, float width, Player* _player) {

	b2Body* body = CreateActorBody(x, y, height, width, 1, EntityType::PLAYER, _player);

	_player->InitActor(body, _hitdmg, _health, width, height, EntityType::PLAYER, bf, drawContainer, moveContainer);
	return _player;
}

Bullet* EntityFactory::CreateBullet(float x, float y,int width,int height, int dmg,b2Vec2 direction, EntityType type){
	Bullet* bullet = bulletRegistery.at(type)->EmptyClone();
	bullet->InitActor(CreateBody(x * 10 - 10, y * 10 - 10, height, width, 500, type), dmg, 1, width, height, type, bf, drawContainer, moveContainer);
	bullet->SetDirection(direction);
	bullet->SetLevel(level);
	actor->push_back(bullet);
	 return bullet;
}

b2Body* EntityFactory::CreateActorBody(float x, float y, float height, float width, float den, EntityType type, Actor* ent){

	height = height / 2;
	width = width / 2;
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;
	float newHeight = (height*Ratio);
	float newWidth = (width*Ratio);

	b2BodyDef bodydef = bodyRegistery.at(type);
	bodydef.position.Set(x*Ratio, y*Ratio);
	b2Body* b2body = world.CreateBody(&bodydef);
	
	b2PolygonShape boxShape;

	//fixture for jumping
	boxShape.SetAsBox(newHeight, newWidth, b2Vec2(newHeight, newWidth), 0);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = den;
	boxFixtureDef.friction = 0.1;
	boxFixtureDef.restitution = 0.7;
	b2body->CreateFixture(&boxFixtureDef);

	b2body->SetTransform(b2Vec2(x*Ratio, y*Ratio), 0);

	return b2body;
}

b2Body* EntityFactory::CreateBody(float x, float y, float height, float width, float den,EntityType type)
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

	boxFixtureDef.density = den;

	boxFixtureDef.friction = 0.1;
	boxFixtureDef.restitution = 0.7;

	b2BodyDef bodydef = bodyRegistery.at(type);
	bodydef.position.Set(x*Ratio, y*Ratio);
	b2Body* b2body = world.CreateBody(&bodydef);

	b2body->CreateFixture(&boxFixtureDef);
	b2body->SetTransform(b2Vec2(x*Ratio, y*Ratio), 0);

	return b2body;
}
