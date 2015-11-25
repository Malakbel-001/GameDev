#include "DrawableBehaviour.h"
#include "Entity.h"

Entity;
DrawableBehaviour::DrawableBehaviour(SDL_Renderer* sdl_renderer, Sprite* _sprite, int screenwidth, int screenheight)
{
	
	renderer = sdl_renderer;
	sprite = _sprite;
	screenWidth = screenwidth;
	screenHeight = screenheight;
	currentFrame = 0;	
}


DrawableBehaviour::~DrawableBehaviour()
{
}

DrawableBehaviour* DrawableBehaviour::EmptyClone()
{ 
	return nullptr; 
}

void DrawableBehaviour::SetEntity(Entity* _entity)
{
	entity = _entity;
}

void DrawableBehaviour::Draw()
{
	//printf("Behaviour not initialized");
}

void DrawableBehaviour::SetSprite(Sprite* _sprite)
{
	sprite = _sprite;
}

void DrawableBehaviour::SetCamera(Camera* _camera){
	camera = _camera;
}
Entity* DrawableBehaviour::GetEntity(){
	return entity;
}