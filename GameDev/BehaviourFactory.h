#pragma once
#include <unordered_map>
#include "BehaviourType.h"

#include "PlayerDrawableBehaviour.h"
#include "AnimatedDrawableBehaviour.h"
#include "StaticDrawableBehaviour.h"
#include "CheatLoadDrawableBehaviour.h" //temp

#include "AttackMoveableBehaviour.h"

#include "PlayerCollidableBehaviour.h"
#include "EnemyCollidableBehaviour.h"
#include "BulletCollidableBehaviour.h"
#include "EntityType.h"


#include "GroundSprite.h"
#include "GroundObstacleSprite.h"
#include "BarObstacleSprite.h"
#include "PlantSprite.h"
#include "PlantBossSprite.h"
#include "PlayerSprite.h"
#include "AcornSprite.h"

class BehaviourFactory
{
public:
	BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight);
	~BehaviourFactory();

	DrawableBehaviour* CreateDrawableBehaviour(EntityType type);
	MoveableBehaviour* CreateMoveableBehaviour(EntityType type, EntityState state, EntityFactory* _ef);
	CollidableBehaviour* CreateCollidableBehaviour(EntityType type);
	SDL_Renderer* GetRenderer();

	void SetLevelToCamera(Player* player, double levelWidth, double levelheight);
private:
	Camera* camera;

	int screenWidth;
	int screenHeight;
	SDL_Renderer* renderer;
	std::unordered_map<EntityType, DrawableBehaviour*> registery;
	std::unordered_map<EntityType, CollidableBehaviour*> collideRegistery;
	std::unordered_map<EntityType, MoveableBehaviour*> moveRegistery;
	std::unordered_map<EntityType, Sprite*> spriteRegistery;
};

