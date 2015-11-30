#pragma once
#include "BehaviourFactory.h"
#include "Camera.h"
#include "CollidableBehaviour.h"
#include "Player.h"
#include "PlayerCollidableBehaviour.h"
#include "EnemyCollidableBehaviour.h"
#include "BulletCollidableBehaviour.h"
#include "HealthCollidableBehaviour.h"
#include "AmmoCollidableBehaviour.h"
#include "HealthSprite.h"
#include "BulletSprite.h"
#include "AmmoSprite.h"
#include "GunSprite.h"
#include "JumpSensorCollidableBehaviour.h"

BehaviourFactory::BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight)
{
	renderer = sdl_renderer;
	screenWidth = screenwidth;
	screenHeight = screenheight;
	camera = new Camera(screenHeight, screenwidth);

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

	PlayerSprite* playerSprite = new PlayerSprite(renderer);
	playerSprite->LoadMedia("sprites.png");


	HealthSprite* healthSprite = new HealthSprite(renderer);
	healthSprite->LoadMedia("HealthSprite.png");



	BulletSprite* bulletSprite = new BulletSprite(renderer);
	bulletSprite->LoadMedia("Bullet.png");

	AmmoSprite* ammoSprite = new AmmoSprite(renderer);
	ammoSprite->LoadMedia("AmmoBox.png");

	GunSprite* gun = new GunSprite(renderer);
	gun->LoadMedia("Gun.png");
		
	registery = std::unordered_map<EntityType, DrawableBehaviour*>{
		{ EntityType::PLAYER, new PlayerDrawableBehaviour(renderer, playerSprite, screenWidth, screenHeight) },
		{ EntityType::PLANT, new AnimatedDrawableBehaviour(renderer, plantSprite, screenWidth, screenHeight) },
		{ EntityType::PLANTBOSS, new AnimatedDrawableBehaviour(renderer, plantBossSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND, new StaticDrawableBehaviour(renderer, groundSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND2, new StaticDrawableBehaviour(renderer, groundobstacleSprite, screenWidth, screenHeight) },
		{ EntityType::BAR, new StaticDrawableBehaviour(renderer, barobstacleSprite, screenWidth, screenHeight) },
		{ EntityType::BULLET, new StaticDrawableBehaviour(renderer, bulletSprite, screenWidth, screenHeight) },
		{ EntityType::HEALTH, new StaticDrawableBehaviour(renderer, healthSprite, screenWidth, screenHeight) },
		{EntityType::AMMO, new StaticDrawableBehaviour(renderer,ammoSprite,screenWidth,screenHeight)},
		{ EntityType::WEAPON, new StaticDrawableBehaviour(renderer, gun, screenWidth, screenHeight) },
		{ EntityType::SHOTGUN, new StaticDrawableBehaviour(renderer, gun, screenWidth, screenHeight) }

	};

	collideRegistery = std::unordered_map < EntityType, CollidableBehaviour* > {
			{ EntityType::PLAYER, new PlayerCollidableBehaviour()},
			{ EntityType::PLANT, new EnemyCollidableBehaviour() },
			{ EntityType::PLANTBOSS, new EnemyCollidableBehaviour() },
			{ EntityType::BULLET, new BulletCollidableBehaviour() },
			{ EntityType::HEALTH, new HealthCollidableBehaviour() },
			{ EntityType::AMMO, new AmmoCollidableBehaviour() },
			{ EntityType::JUMP, new JumpSensorCollidableBehaviour()}


	};

}


SDL_Renderer* BehaviourFactory::GetRenderer(){
	return renderer;
}


BehaviourFactory::~BehaviourFactory()
{
	registery.clear();
}

DrawableBehaviour* BehaviourFactory::CreateDrawableBehaviour(EntityType type)
{
	DrawableBehaviour* behaviour = registery.at(type)->EmptyClone();
	behaviour->SetCamera(camera);
	return behaviour;
}

CollidableBehaviour* BehaviourFactory::CreateCollidableBehaviour(EntityType type)
{
	CollidableBehaviour* behaviour = collideRegistery.at(type)->EmptyClone();
	return behaviour;
}

void BehaviourFactory::SetLevelToCamera(Player* player,double levelWidth,double levelheight){
	camera->Init(player, levelWidth, levelheight);
}