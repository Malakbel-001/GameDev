#include "Sprite.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer* _renderer)
{
	idleSprites = nullptr;
	walkSprites = nullptr;
	dyingSprites = nullptr;
	spriteSheetTexture = nullptr;
	xOffSet = 0;
	yOffSet = 0;
	renderer = _renderer;
	spriteSheetTexture = new LTexture();
	currentSprites = nullptr;
	idleSprites = new std::vector<SDL_Rect>();
	walkSprites = new std::vector<SDL_Rect>();
	dyingSprites = new std::vector<SDL_Rect>();
	spriteYOffset = new std::vector<float>();
	spriteXOffset = new std::vector<float>();

}


Sprite::~Sprite()
{
	if (idleSprites){
		delete idleSprites;
		idleSprites = nullptr;
	}
	if (walkSprites){
		delete walkSprites;
		walkSprites = nullptr;
	}
	if (dyingSprites){
		delete dyingSprites;
		dyingSprites = nullptr;
	}
	delete spriteSheetTexture;

}
float Sprite::GetXOffSet(){
	return xOffSet;
}
float Sprite::GetYOffSet(){
	return yOffSet;
}

float Sprite::GetFrameYOffSet(int frame){
	if (spriteYOffset->size() > 0){
		return spriteYOffset->at(frame);
	}
	else {
		return 0;
	}
}

float Sprite::GetFrameXOffSet(int frame){
	if (spriteXOffset->size() > 0){
		return spriteXOffset->at(frame);
	}
	else {
		return 0;
	}
}

SDL_Rect* Sprite::GetAnimationFrame(EntityState state, int frame)
{
	switch (state)
	{
	case EntityState::IDLE:
		return &idleSprites->at(frame);
		break;
	case EntityState::WALKINGLEFT:		
		return &walkSprites->at(frame);
		break;
	case EntityState::WALKINGRIGHT:
		return &walkSprites->at(frame);
		break;
	case EntityState::JUMPING:
		break;
	case EntityState::SHOOTING:
		break;
	case EntityState::DYING:
		return &dyingSprites->at(frame);
		break;
	case EntityState::DEFAULT:
		if (idleSprites->size() > 0) {
			return &idleSprites->at(frame);
		}
		else if (walkSprites->size() > 0) {
			return &walkSprites->at(frame);
		}
		else {
			return &defaultSprite;
		}
	default:
		return &defaultSprite;
		break;
	}
}

int Sprite::GetAnimationSize(EntityState state)
{
	switch (state)
	{
	case EntityState::IDLE:
		return idleSprites->size();
		break;
	case EntityState::WALKINGLEFT:
		return walkSprites->size();
		break;
	case EntityState::WALKINGRIGHT:
		return walkSprites->size();
		break;
	case EntityState::JUMPING:
		break;
	case EntityState::SHOOTING:
		break;
	case EntityState::DYING:
		return dyingSprites->size();
		break;
	case EntityState::DEFAULT:
		if (idleSprites->size() > 0) {
			return idleSprites->size();
		}
		else if (walkSprites->size() > 0) {
			return walkSprites->size();
		}
		return 1;
	default:
		return 1;
		break;
	}
}

void Sprite::SetAnimationSet(EntityState state)
{
	switch (state)
	{
		case EntityState::IDLE:
			currentSprites = idleSprites;
			CURRENT_ANIMATION_FRAMES = IDLE_ANIMATION_FRAMES;
			break;
		case EntityState::WALKINGLEFT:
			currentSprites = walkSprites;
			CURRENT_ANIMATION_FRAMES = WALK_ANIMATION_FRAMES;
			break;
		case EntityState::WALKINGRIGHT:
			currentSprites = walkSprites;
			CURRENT_ANIMATION_FRAMES = WALK_ANIMATION_FRAMES;
			break;
		case EntityState::JUMPING:
			break;
		case EntityState::SHOOTING:
			break;
		case EntityState::DYING:
			currentSprites = dyingSprites;
			CURRENT_ANIMATION_FRAMES = DYING_ANIMATION_FRAMES;
			break;
		default:
			currentSprites = idleSprites;
			break;
	}
}

void Sprite::SetRenderer(SDL_Renderer* _renderer)
{
	renderer = _renderer;
}

LTexture* Sprite::GetSpritesheet()
{
	return spriteSheetTexture;
}

bool Sprite::LoadMedia(std::string path)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (renderer == nullptr)
	{
		printf("Failed to load spritesheet! Renderer has not been set. \n");
		success = false;
	}
	else 
	{
		if (!spriteSheetTexture->loadFromFile(renderer, path))
		{
			printf("Failed to load spritesheet! \n");
			success = false;
		}
	}
	return success;
}

void Sprite::SetAnimations()
{
	printf("Sprite::SetAnimations: Not implemented yet!");
}