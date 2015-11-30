#include "BehaviourFactory.h"

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
	plantBossSprite->SetAnimationSet(EntityState::IDLE);

	AcornSprite* acornSprite = new AcornSprite(renderer);
	acornSprite->LoadMedia("plantboss.png");
	acornSprite->SetAnimationSet(EntityState::IDLE);

	PlayerSprite* playerSprite = new PlayerSprite(renderer);
	playerSprite->LoadMedia("sprites.png");
		
	registery = std::unordered_map<EntityType, DrawableBehaviour*>{
		{ EntityType::PLAYER, new PlayerDrawableBehaviour(renderer, playerSprite, screenWidth, screenHeight) },
		{ EntityType::PLANT, new AnimatedDrawableBehaviour(renderer, plantSprite, screenWidth, screenHeight) },
		{ EntityType::PLANTBOSS, new AnimatedDrawableBehaviour(renderer, plantBossSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND, new StaticDrawableBehaviour(renderer, groundSprite, screenWidth, screenHeight) },
		{ EntityType::GROUND2, new StaticDrawableBehaviour(renderer, groundobstacleSprite, screenWidth, screenHeight) },
		{ EntityType::BAR, new StaticDrawableBehaviour(renderer, barobstacleSprite, screenWidth, screenHeight) },
		{ EntityType::BULLET, new AnimatedDrawableBehaviour(renderer, plantSprite, screenWidth, screenHeight) },
		{ EntityType::ACORN, new AnimatedDrawableBehaviour(renderer, acornSprite, screenWidth, screenHeight) },
		{ EntityType::CHEATLOAD, new CheatLoadDrawableBehaviour(renderer, playerSprite, screenWidth, screenHeight) }
	};

	collideRegistery = std::unordered_map < EntityType, CollidableBehaviour* > {
		{ EntityType::PLAYER, new PlayerCollidableBehaviour()},
		{ EntityType::PLANT, new EnemyCollidableBehaviour() },
		{ EntityType::PLANTBOSS, new EnemyCollidableBehaviour() },
		{ EntityType::BULLET, new BulletCollidableBehaviour() },
		{ EntityType::ACORN, new BulletCollidableBehaviour() }
	};

	moveRegistery = std::unordered_map < EntityType, MoveableBehaviour* > {
		{ EntityType::PLANT, new AttackMoveableBehaviour() },
		{ EntityType::PLANTBOSS, new AttackMoveableBehaviour() }
	};

	spriteRegistery = std::unordered_map<EntityType, Sprite*>{
		{ EntityType::PLAYER, playerSprite },
		{ EntityType::PLANT, plantSprite },
		{ EntityType::GROUND, groundSprite },
		{ EntityType::GROUND2, groundobstacleSprite },
		{ EntityType::BAR, barobstacleSprite },
		{ EntityType::BULLET, plantSprite },
		{ EntityType::PLANTBOSS, plantBossSprite },
		{ EntityType::ACORN, acornSprite }
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

MoveableBehaviour* BehaviourFactory::CreateMoveableBehaviour(EntityType type, EntityState state, EntityFactory* _ef)
{
	MoveableBehaviour* behaviour = moveRegistery.at(type)->EmptyClone();
	behaviour->SetEntityFactory(_ef);
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