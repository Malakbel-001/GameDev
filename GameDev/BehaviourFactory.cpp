#pragma once
#include "BehaviourFactory.h"
#include "Camera.h"
#include "CollidableBehaviour.h"
#include "PlayerCollidableBehaviour.h"
#include "EnemyCollidableBehaviour.h"
#include "BulletCollidableBehaviour.h"
#include "HealthCollidableBehaviour.h"
#include "AmmoCollidableBehaviour.h"
#include "JumpSensorCollidableBehaviour.h"
#include "StepCollidableBehaviour.h"
#include "ApcMoveableBehaviour.h"
#include "HealthSprite.h"
#include "BulletSprite.h"
#include "AmmoSprite.h"
#include "GunSprite.h"
#include "CannonshotSprite.h"
#include "ApcSprite.h"

BehaviourFactory::BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight)
{
	renderer = sdl_renderer;
	screenWidth = screenwidth;
	screenHeight = screenheight;
	camera = new Camera(screenHeight, screenwidth);
	sprites = std::vector<Sprite*>();

	GroundSprite* groundSprite = new GroundSprite(renderer);
	groundSprite->LoadMedia("grass.png");

	GroundObstacleSprite* groundobstacleSprite = new GroundObstacleSprite(renderer);
	groundobstacleSprite->LoadMedia("grass.png");

	BarObstacleSprite* barobstacleSprite = new BarObstacleSprite(renderer);
	barobstacleSprite->LoadMedia("grass.png");

	PlantSprite* plantSprite = new PlantSprite(renderer);
	plantSprite->LoadMedia("plant.png");
	plantSprite->SetAnimationSet(EntityState::IDLE);

	PlantBossSprite* plantBossSprite = new PlantBossSprite(renderer);
	plantBossSprite->LoadMedia("plantboss.png");
	plantBossSprite->SetAnimationSet(EntityState::IDLE);

	AcornSprite* acornSprite = new AcornSprite(renderer);
	acornSprite->LoadMedia("plantboss.png");
	acornSprite->SetAnimationSet(EntityState::IDLE);

	PlayerSprite* playerSprite = new PlayerSprite(renderer);
	playerSprite->LoadMedia("sprites.png");

	TankSprite* tankSprite = new TankSprite(renderer);
	tankSprite->LoadMedia("MetalSlugTank.png");
	tankSprite->SetAnimationSet(EntityState::IDLE);

	ApcSprite* apcSprite = new ApcSprite(renderer);
	apcSprite->LoadMedia("apc_template.png");

	MechSprite* mechSprite = new MechSprite(renderer);
	mechSprite->LoadMedia("mech.png");
	mechSprite->SetAnimationSet(EntityState::IDLE);

	HealthSprite* healthSprite = new HealthSprite(renderer);
	healthSprite->LoadMedia("HealthSprite.png");



	BulletSprite* bulletSprite = new BulletSprite(renderer);
	bulletSprite->LoadMedia("Bullet.png");

	CannonshotSprite* cannonshotSprite = new CannonshotSprite(renderer);
	cannonshotSprite->LoadMedia("M484BulletCollection1.png");

	AmmoSprite* ammoSprite = new AmmoSprite(renderer);
	ammoSprite->LoadMedia("AmmoBox.png");

	GunSprite* gun = new GunSprite(renderer);
	gun->LoadMedia("Gun.png");

	GunSprite* cannon = new GunSprite(renderer);

	GroundLvl2Sprite* groundlvl2Sprite = new GroundLvl2Sprite(renderer);
	groundlvl2Sprite->LoadMedia("snow2.png");

	BigGroundSprite* bigGroundSprite = new BigGroundSprite(renderer);
	bigGroundSprite->LoadMedia("snow2.png");

	DesertGroundSprite* desertgroundSprite = new DesertGroundSprite(renderer);
	desertgroundSprite->LoadMedia("Desert.png");

	PinguinSprite* pinguinSprite = new PinguinSprite(renderer);
	pinguinSprite->LoadMedia("pinguin.png");
	pinguinSprite->SetAnimationSet(EntityState::IDLE);

	//leaks 
	TreeSprite* treeSprite = new TreeSprite(renderer);
	treeSprite->LoadMedia("tree.png");

	ShotgunSprite* shotgun = new ShotgunSprite(renderer);
	shotgun->LoadMedia("shotgun.png");

	SnowmanSprite* snowman = new SnowmanSprite(renderer);
	snowman->LoadMedia("yeti.png");
	snowman->SetAnimationSet(EntityState::IDLE);

	SnowBossSprite* snowBoss = new SnowBossSprite(renderer);
	snowBoss->LoadMedia("snowball.png");

	sprites.push_back(snowman);
	sprites.push_back(groundSprite);
	sprites.push_back(groundobstacleSprite);
	sprites.push_back(barobstacleSprite);
	sprites.push_back(plantSprite);
	sprites.push_back(plantBossSprite);
	sprites.push_back(acornSprite);
	sprites.push_back(playerSprite);
	sprites.push_back(tankSprite);
	sprites.push_back(mechSprite);
	sprites.push_back(apcSprite);
	sprites.push_back(healthSprite);
	sprites.push_back(bulletSprite); 
	sprites.push_back(cannonshotSprite);
	sprites.push_back(ammoSprite);
	sprites.push_back(gun);
	sprites.push_back(groundlvl2Sprite);
	sprites.push_back(desertgroundSprite);
	sprites.push_back(pinguinSprite); 
	sprites.push_back(treeSprite);
	sprites.push_back(shotgun);
	sprites.push_back(bigGroundSprite);
	sprites.push_back(snowBoss);
	sprites.push_back(cannon);

	registery = std::unordered_map<EntityType, DrawableBehaviour*>{
		{ EntityType::PLAYER, new PlayerDrawableBehaviour(renderer, playerSprite, screenWidth, screenHeight) },
		{ EntityType::PLANT, new AnimatedDrawableBehaviour(renderer, plantSprite, screenWidth, screenHeight) },
		{ EntityType::PLANTBOSS, new AnimatedDrawableBehaviour(renderer, plantBossSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND, new StaticDrawableBehaviour(renderer, groundSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND2, new StaticDrawableBehaviour(renderer, groundobstacleSprite, screenWidth, screenHeight) },
		{ EntityType::BAR, new StaticDrawableBehaviour(renderer, barobstacleSprite, screenWidth, screenHeight) },
		{ EntityType::HEALTH, new StaticDrawableBehaviour(renderer, healthSprite, screenWidth, screenHeight) },
		{ EntityType::AMMO, new StaticDrawableBehaviour(renderer,ammoSprite,screenWidth,screenHeight)},
		{ EntityType::WEAPON, new StaticDrawableBehaviour(renderer, gun, screenWidth, screenHeight) },
		{ EntityType::SHOTGUN, new StaticDrawableBehaviour(renderer, shotgun, screenWidth, screenHeight) },
		{ EntityType::CANNON, new StaticDrawableBehaviour(renderer, cannon, screenWidth, screenHeight) },
		{ EntityType::BULLET, new StaticDrawableBehaviour(renderer, bulletSprite, screenWidth, screenHeight) },
		{ EntityType::ACORN, new AnimatedDrawableBehaviour(renderer, acornSprite, screenWidth, screenHeight) },
		{ EntityType::CANNONSHOT, new StaticDrawableBehaviour(renderer, cannonshotSprite, screenWidth, screenHeight) },
	//	{ EntityType::CHEATLOAD, new CheatLoadDrawableBehaviour(renderer, playerSprite, screenWidth, screenHeight) },	
	
	//level2
		{ EntityType::GROUNDLVL2, new StaticDrawableBehaviour(renderer, groundlvl2Sprite, screenWidth, screenHeight) },
		{ EntityType::PINGUIN, new AnimatedDrawableBehaviour(renderer, pinguinSprite, screenWidth, screenHeight) },
		{ EntityType::SNOWMAN, new AnimatedDrawableBehaviour(renderer, snowman, screenWidth, screenHeight) },
		{ EntityType::PLAYERSPRITE, new AnimatedDrawableBehaviour(renderer, playerSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND2LVL2, new StaticDrawableBehaviour(renderer, bigGroundSprite, screenWidth, screenHeight) },
		{ EntityType::SNOWBOSS, new StaticDrawableBehaviour(renderer, snowBoss, screenWidth, screenHeight) },
	
	//level3
		{ EntityType::DESERTFLOOR, new StaticDrawableBehaviour(renderer, desertgroundSprite, screenWidth, screenHeight) },
		{ EntityType::TANK, new AnimatedDrawableBehaviour(renderer, tankSprite, screenWidth, screenHeight) },
		{ EntityType::MECH, new AnimatedDrawableBehaviour(renderer, mechSprite, screenWidth, screenHeight) },
		{ EntityType::APC, new StaticDrawableBehaviour(renderer, apcSprite, screenWidth, screenHeight) },
	};
	
	collideRegistery = std::unordered_map < EntityType, CollidableBehaviour* > {
		{ EntityType::PLAYER, new PlayerCollidableBehaviour()},
		{ EntityType::PLANT, new EnemyCollidableBehaviour() },
		{ EntityType::PLANTBOSS, new EnemyCollidableBehaviour() },
		{ EntityType::BULLET, new BulletCollidableBehaviour() },
		{ EntityType::CANNONSHOT, new BulletCollidableBehaviour() },
		{ EntityType::ACORN, new BulletCollidableBehaviour() },
		{ EntityType::PINGUIN, new EnemyCollidableBehaviour() },
		{ EntityType::HEALTH, new HealthCollidableBehaviour() },
		{ EntityType::AMMO, new AmmoCollidableBehaviour() },
		{ EntityType::JUMP, new JumpSensorCollidableBehaviour()},
		{ EntityType::SNOWMAN, new EnemyCollidableBehaviour() },
		{ EntityType::SNOWBOSS, new EnemyCollidableBehaviour() },
		{ EntityType::TANK, new EnemyCollidableBehaviour() },
		{ EntityType::MECH, new EnemyCollidableBehaviour() },
		{ EntityType::APC, new EnemyCollidableBehaviour() },
	};

	IdleCommand* idle = new IdleCommand();
	DefaultPatrolCommand* patrol = new DefaultPatrolCommand();

	defaultCommands = std::unordered_map<EntityState, BaseCommand*> {
		{ EntityState::IDLE, idle }
	};

	plantCommands = std::unordered_map<EntityState, BaseCommand*> {
		{ EntityState::IDLE, patrol },
		{ EntityState::PATROL, idle }
	};
	
	moveRegistery = std::unordered_map < EntityType, MoveableBehaviour* > {
		{ EntityType::ACORN, new MoveableBehaviour(defaultCommands) },
		{ EntityType::AMMO, new MoveableBehaviour(defaultCommands) },
		{ EntityType::BAR, new MoveableBehaviour(defaultCommands) },
		{ EntityType::BULLET, new MoveableBehaviour(defaultCommands) },
		{ EntityType::CANNONSHOT, new MoveableBehaviour(defaultCommands) },
		{ EntityType::GROUND, new MoveableBehaviour(defaultCommands) },
		{ EntityType::GROUND2, new MoveableBehaviour(defaultCommands) },
		{ EntityType::GROUNDLVL2, new MoveableBehaviour(defaultCommands) },
		{ EntityType::GROUND2LVL2, new MoveableBehaviour(defaultCommands) },
		{ EntityType::DESERTFLOOR, new MoveableBehaviour(defaultCommands) },
		{ EntityType::HEALTH, new MoveableBehaviour(defaultCommands) },
		{ EntityType::PINGUIN, new MoveableBehaviour(defaultCommands) },
		{ EntityType::PLANT, new PlantMoveableBehaviour(plantCommands) },
		{ EntityType::PLAYER, new MoveableBehaviour(defaultCommands) },
		{ EntityType::PLAYERSPRITE, new MoveableBehaviour(defaultCommands) },
		{ EntityType::PLANTBOSS, new MoveableBehaviour(defaultCommands) },
		{ EntityType::SHOTGUN, new MoveableBehaviour(defaultCommands) },
		{ EntityType::SNOWMAN, new MoveableBehaviour(defaultCommands) },
		{ EntityType::SNOWBOSS, new MoveableBehaviour(defaultCommands) },
		{ EntityType::TANK, new MoveableBehaviour(defaultCommands) },
		{ EntityType::MECH, new MoveableBehaviour(defaultCommands) },
		{ EntityType::CANNON, new MoveableBehaviour(defaultCommands) },
		{ EntityType::WEAPON, new MoveableBehaviour(defaultCommands) },
		{ EntityType::APC, new ApcMoveableBehaviour(defaultCommands) }
	};
}



SDL_Renderer* BehaviourFactory::GetRenderer(){
	return renderer;
}



BehaviourFactory::~BehaviourFactory()
{
	for each(auto var in sprites){
		delete var;
	}

	for each (auto var in registery)
	{
	
		delete (var.second);

	}
	registery.clear();

	for each (auto var in collideRegistery)
	{
		delete var.second;

	}
	collideRegistery.clear();
	delete camera;
}

ParallaxBackground* BehaviourFactory::CreateEmptyParallaxBehaviour() {
	return new ParallaxBackground(renderer, camera);
}

DrawableBehaviour* BehaviourFactory::CreateDrawableBehaviour(EntityType type)
{
	DrawableBehaviour* behaviour = registery.at(type)->EmptyClone();
	behaviour->SetCamera(camera);
	return behaviour;
}

CollidableBehaviour* BehaviourFactory::CreateCollidableBehaviour(EntityType type, Actor* actor)
{
	CollidableBehaviour* behaviour = collideRegistery.at(type)->EmptyClone();
	
	return behaviour;
}

CollidableBehaviour* BehaviourFactory::CreateStepCollidableBehaviour()
{
	return new StepCollidableBehaviour();
}

MoveableBehaviour* BehaviourFactory::CreateMoveableBehaviour(EntityType type)
{ 
	MoveableBehaviour* behaviour = moveRegistery.at(type)->EmptyClone();
	return behaviour;
}

void BehaviourFactory::ClearCamera(){
	camera->Init(nullptr, 0, 0);
}

void BehaviourFactory::SetLevelToCamera(Player* player,double levelWidth,double levelheight){
	camera->Init(player, levelWidth, levelheight);
}