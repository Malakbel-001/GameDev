#pragma once
#include <unordered_map>
#include "BehaviourType.h"
#include "DrawableBehaviour.h"
#include "PlayerDrawableBehaviour.h"
#include "GroundDrawableBehaviour.h"
#include "GroundObstacleDrawableBehavior.h"
#include "BarObstacleDrawableBehaviour.h"
#include "MoveableBehaviour.h"
#include "CollidableBehaviour.h"
#include "EntityType.h"

class Camera;
class Player;
class BehaviourFactory
{
public:
	BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight);
	~BehaviourFactory();

	DrawableBehaviour* CreateDrawableBehaviour(EntityType type);
	SDL_Renderer* GetRenderer();

	void SetLevelToCamera(Player* player, double levelWidth, double levelheight);
private:
	Camera* camera;
	int screenWidth;
	int screenHeight;
	SDL_Renderer* renderer;
	std::unordered_map<EntityType, DrawableBehaviour*> registery;
};

