#include "BehaviourFactory.h"
#include "Camera.h"


#include "Player.h"
BehaviourFactory::BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight)
{
	renderer = sdl_renderer;
	screenWidth = screenwidth;
	screenHeight = screenheight;
	camera = new Camera(screenHeight, screenwidth);

	registery = std::unordered_map<EntityType, DrawableBehaviour*>{
			{ EntityType::PLAYER, new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight) },
			{ EntityType::GROUND, new GroundDrawableBehaviour(renderer, screenWidth, screenHeight) },
			{ EntityType::GROUND2, new GroundObstacleDrawableBehavior(renderer, screenWidth, screenHeight) },
			{ EntityType::BAR, new BarObstacleDrawableBehaviour(renderer, screenWidth, screenHeight) }
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

void BehaviourFactory::SetLevelToCamera(Player* player,double levelWidth,double levelheight){
	camera->Init(player, levelWidth, levelheight);
}