#include "DrawableBehaviour.h"
#include "Object.h"

//Entity;
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

void DrawableBehaviour::SetEntity(Object* _entity)
{
	entity = _entity;
}

Sprite* DrawableBehaviour::GetSprite(){
	return sprite;
}
void DrawableBehaviour::SetSprite(Sprite* _sprite)
{
	sprite = _sprite;
}

void DrawableBehaviour::SetCamera(Camera* _camera){
	camera = _camera;
}
Object* DrawableBehaviour::GetEntity(){
	return entity;
}

//The Dream! To make this properly work. This'd fix some repeated code
//void DrawableBehaviour::CycleFrames(bool cycle) {
//	if (cycle) {
//		int size = sprite->GetAnimationSize(entity->GetState()); // /3
//		//Cycle animation 
//
//		if (currentFrame >= size)
//		{
//			currentFrame = 0;
//		}
//
//		currentFrame++;
//	}
//}