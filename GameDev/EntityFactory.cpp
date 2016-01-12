
#include "EntityFactory.h"



EntityFactory::EntityFactory(b2World& b2world, std::vector<Actor*>* _actor, std::vector<Entity*>* _ent, BehaviourFactory* _bf, Level* _level, DrawableContainer* _drawContainer, MoveableContainer* _moveContainer) : world(b2world), actor(_actor), bf(_bf), level(_level), drawContainer(_drawContainer), moveContainer(_moveContainer), entities(_ent)
{
	actorRegistery = std::unordered_map<EntityType, Actor*>{
		{ EntityType::ACTOR, new Actor() },
		{ EntityType::TANK, new Vehicle() },
		{ EntityType::MECH, new Vehicle() },
		{ EntityType::NPC, new Npc(this) },
		{ EntityType::PLAYER, new Player() },
		{ EntityType::PLANT, new Npc(this) },
		{ EntityType::PLANTBOSS, new Npc(this) },
		{ EntityType::BULLET, new Bullet() },
		{ EntityType::CANNONSHOT, new Bullet() },
		{ EntityType::ACORN, new Bullet() },
		{ EntityType::PINGUIN, new Npc(this) },
		{ EntityType::HEALTH, new Actor()},
		{ EntityType::AMMO, new Actor() },
		{ EntityType::SNOWBOSS, new Npc(this) },
		{ EntityType::SNOWMAN, new Npc(this) },
		{ EntityType::APC, new Apc(this) },
		{ EntityType::MINIGUNNER, new Npc(this) },
	};

	//collision filtering flags
	entityCollisionRegistery = std::unordered_map<EntityType, CollisionType> {
		{ EntityType::PLAYER, CollisionType::ALLY },
		{ EntityType::MECH, CollisionType::ALLY },

		{ EntityType::PLANT, CollisionType::ENEMY },
		{ EntityType::PLANTBOSS, CollisionType::ENEMY },
		{ EntityType::PINGUIN, CollisionType::ENEMY },
		{ EntityType::SNOWMAN, CollisionType::ENEMY },
		{ EntityType::SNOWBOSS, CollisionType::ENEMY },
		{ EntityType::APC, CollisionType::ENEMY },
		{ EntityType::MINIGUNNER, CollisionType::ENEMY },
	};

	entityRegistery = std::unordered_map<EntityType, Entity*>{
		{ EntityType::ENTITY, new Entity() },	
		{ EntityType::GROUND, new Ground() },
		{ EntityType::GROUND2, new Ground() },
		{ EntityType::BAR, new Ground() },

		//level2
		{ EntityType::GROUNDLVL2, new Ground() },
		{ EntityType::GROUND2LVL2, new Ground() },

		//level3
		{ EntityType::DESERTFLOOR, new Ground() },
		{ EntityType::SMALLDESERTFLOOR, new Ground() },
	};

	weaponRegistery = std::unordered_map < EntityType, Weapon* > {
			{ EntityType::WEAPON, new Weapon() },
			{ EntityType::SHOTGUN, new ShotGun() },
			{ EntityType::CANNON, new Cannon() },
	};

	bulletRegistery = std::unordered_map < EntityType, Bullet* > {
			{ EntityType::BULLET ,new Bullet() },
			{ EntityType::CANNONSHOT, new Bullet() },
			{ EntityType::ACORN, new Bullet() }

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
	PlantBossDef.gravityScale = 5;
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

	b2BodyDef SnowBossDef = b2BodyDef();
	SnowBossDef.gravityScale = 0.0f;
	SnowBossDef.fixedRotation = true;
	SnowBossDef.linearDamping = 0;
	SnowBossDef.angularDamping = 0.01f;
	SnowBossDef.type = b2BodyType::b2_dynamicBody;

	b2BodyDef MinigunnerDef = b2BodyDef();
	MinigunnerDef.gravityScale = 1;
	MinigunnerDef.fixedRotation = true;
	MinigunnerDef.linearDamping = 0.5f;
	MinigunnerDef.angularDamping = 1;
	MinigunnerDef.type = b2BodyType::b2_dynamicBody;

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
		{ EntityType::CANNONSHOT, Bullet },
		{ EntityType::HEALTH, Health },
		{ EntityType::AMMO, Ammo },
		{ EntityType::ACORN, Bullet },
		
		//level2
		{ EntityType::GROUNDLVL2, entDef },
		{ EntityType::PINGUIN, PlantDef },
		{ EntityType::SNOWMAN, SnowmanDef },
		{ EntityType::GROUND2LVL2, entDef },
		{ EntityType::SNOWBOSS, SnowBossDef },

		//level3
		{ EntityType::DESERTFLOOR, entDef },
		{ EntityType::SMALLDESERTFLOOR, entDef },
		{ EntityType::TANK, TankDef },
		{ EntityType::APC, TankDef },
		{ EntityType::MECH, MechDef },
		{ EntityType::MINIGUNNER, MinigunnerDef },
	};

	npcStatsRegistery = std::unordered_map < EntityType, NpcStatsContainer* > {
		{ EntityType::PLANT, new NpcStatsContainer(25, 50, 100, 40, 45) },
		{ EntityType::PLANTBOSS, new NpcStatsContainer(50, 500, 1000, 100, 100) },
		{ EntityType::PINGUIN, new NpcStatsContainer(34, 75, 200, 24, 36) },
		{ EntityType::SNOWMAN, new NpcStatsContainer(45, 130, 250, 42, 34) },
		{ EntityType::SNOWBOSS, new NpcStatsContainer(30, 400, 2500, 120, 122) },
		{ EntityType::TANK, new NpcStatsContainer(0, 500, 0, 55, 65) },
		{ EntityType::APC, new NpcStatsContainer(0, 500, 4000, 143, 128) },
		{ EntityType::MECH, new NpcStatsContainer(0, 500, 0, 193, 85) },
		{ EntityType::MINIGUNNER, new NpcStatsContainer(0, 150, 200, 42, 63) },
	};

	//bounciness
	restitutionRegistery = std::unordered_map < EntityType, float > {
		{ EntityType::PLAYER, 0.5f },
		{ EntityType::SNOWBOSS ,20.0f},
		//SnowBoss?
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
	for (auto it = npcStatsRegistery.begin(); it != npcStatsRegistery.end(); ++it) 
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
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;
	Actor* ent = actorRegistery.at(type)->EmptyClone();
	if (npcStatsRegistery.find(type) == npcStatsRegistery.end()) { //error handling, avoid crashing
		std::cout << "Actor: " << "[insert EntityType here] " << "is not found in the npcStatsRegistery - CreateActor!" << std::endl;
	}
	else {
		NpcStatsContainer* npcStats = npcStatsRegistery.at(type);
		b2Body* body;
		if (type == EntityType::SNOWBOSS){
			body = CreateActorRoundBody(x, y, npcStats->GetHeight(), npcStats->GetWidth(), 1, type, ent);
		
		}
		else {
			body = CreateActorBody(x, y, npcStats->GetHeight(), npcStats->GetWidth(), 1, type, ent);
		}
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

//Creates Bullet
//ally -> when the Bullet is fired from an Ally, which will only hit the enemy
//type -> refers to the Bullet EntityType
//b2Vec2 direction -> direction the Bullet flies including speed
Bullet* EntityFactory::CreateBullet(float x, float y, int width, int height, int dmg, 
		b2Vec2 direction, uint16 categoryBits, EntityType type){

	Bullet* bullet = bulletRegistery.at(type)->EmptyClone();

	b2Body* b2body = CreateBody(x * 10 - 10, y * 10 - 10, height, width, 500, type);
	//b2body->SetGravityScale(0); //this would set the Bullet to gravity 0, probably. Might be useful
	//bodyDef.bullet = true; //look at the box2d manual. Might be useful

	b2Filter collisionFilter = b2body->GetFixtureList()->GetFilterData();

	//collision filtering, bullet collides with stuff
	if (categoryBits == (uint16)CollisionType::ALLY) {
		//this bullet is now classified as Ally
		collisionFilter.categoryBits = (uint16)CollisionType::ALLYBULLET;
		//and will only collide with OTHER
		collisionFilter.maskBits = (uint16)CollisionType::OTHER | (uint16)CollisionType::ENEMY;
		//collisionFilter.maskBits = (uint16)CollisionType::ENEMY; //this for example, makes the bullets fly through walls =D
	}
	else {
		//this bullet is now classified as EnemyBullet
		collisionFilter.categoryBits = (uint16)CollisionType::ENEMYBULLET;
		//and will only collide with OTHER
		collisionFilter.maskBits = (uint16)CollisionType::OTHER | (uint16)CollisionType::ALLY;
	}

	//adds the Collision Filtering to the Bullet body
	b2body->GetFixtureList()->SetFilterData(collisionFilter);

	bullet->InitActor(b2body, dmg, 1, width, height, type, bf, drawContainer, moveContainer);
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

	//categorising the body in a collision filter
	if (entityCollisionRegistery.find(type) == entityCollisionRegistery.end())
		boxFixtureDef.filter.categoryBits = (uint16)CollisionType::OTHER;
	else //FYI: define collision types for entities in entityCollisionRegistery
		boxFixtureDef.filter.categoryBits = (uint16)entityCollisionRegistery.at(type);

	//friction is applied when an Entity glides on the ground. More friction -> entity slows down faster
	boxFixtureDef.friction = 2; //changed - old value:0.1 -> new value: 10

	if (restitutionRegistery.find(type) == restitutionRegistery.end()){
		boxFixtureDef.restitution = 0.7;
	}
	else{ //FYI: define other restitution in the restitutionRegistery
		boxFixtureDef.restitution = restitutionRegistery.at(type);
	}
	b2body->CreateFixture(&boxFixtureDef);

	b2body->SetTransform(b2Vec2(x*Ratio, y*Ratio), 0);

	return b2body;
}

b2Body* EntityFactory::CreateActorRoundBody(float x, float y, float height, float width, float den, EntityType type, Actor* ent){

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

	b2CircleShape circleShape;
	circleShape.m_p.Set((newWidth), (newHeight)); //position, relative to body position
	circleShape.m_radius = newWidth; //radius

	//fixture for jumping
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
	b2body->CreateFixture(&myFixtureDef); //add a fixture to the body

	b2body->SetTransform(b2Vec2(x*Ratio, y*Ratio), 0);

	return b2body;
}

/*b2Body* EntityFactory::CreateActorBodyRound(float x, float y, float height, float width, float den, EntityType type){
	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = 1;

	height = height / 2;
	width = width / 2;
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;
	float newHeight = (height*Ratio);
	float newWidth = (width*Ratio);

	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
	//SnowBossDef->CreateFixture(&myFixtureDef); //add a fixture to the body
}*/

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
