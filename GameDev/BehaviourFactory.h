#pragma once
#include <unordered_map>
#include "ParallaxBackground.h"
#include "BehaviourType.h"
#include "DrawableBehaviour.h"
#include "PlayerDrawableBehaviour.h"
#include "AnimatedDrawableBehaviour.h"
#include "StaticDrawableBehaviour.h"
#include "MoveableBehaviour.h"
#include "EntityType.h"
#include "CheatLoadDrawableBehaviour.h" //temp
#include "GroundSprite.h"
#include "GroundObstacleSprite.h"
#include "BarObstacleSprite.h"
#include "PlantSprite.h"
#include "PlantBossSprite.h"
#include "PlayerSprite.h"
#include "AcornSprite.h"
#include "ShotgunSprite.h"
//level2
#include "GroundLvl2Sprite.h"
#include "PinguinSprite.h"
#include "TreeSprite.h"
#include "SnowmanSprite.h"


class Camera;
class Player;
class CollidableBehaviour;
class BehaviourFactory
{
	public:
		BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight);
		~BehaviourFactory();

		ParallaxBackground* CreateEmptyParallaxBehaviour();
		DrawableBehaviour* CreateDrawableBehaviour(EntityType type);
		CollidableBehaviour* CreateCollidableBehaviour(EntityType type);
		SDL_Renderer* GetRenderer();
		void ClearCamera();
		void SetLevelToCamera(Player* player, double levelWidth, double levelheight);
	private:
		Camera* camera;

		int screenWidth;
		int screenHeight;
		SDL_Renderer* renderer;
		std::unordered_map<EntityType, DrawableBehaviour*> registery;
		std::unordered_map<EntityType, CollidableBehaviour*> collideRegistery;
		std::unordered_map<EntityType, Sprite*> spriteRegistery;
		std::vector<Sprite*> sprites;
};

