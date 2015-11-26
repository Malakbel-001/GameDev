#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* _renderer)
{
	renderer = _renderer;
	spriteSheetTexture = new LTexture();
	currentSprites = nullptr;
	idleSprites = new std::vector<SDL_Rect>();
	walkSprites = new std::vector<SDL_Rect>();
}


Sprite::~Sprite()
{
	delete renderer;
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
	case EntityState::DEFAULT:
		return &defaultSprite;
	default:
		return &defaultSprite;
		break;
	}
}

int Sprite::GetAnimationSize()
{
	if (currentSprites == nullptr)
		return 1;
	return currentSprites->size();
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