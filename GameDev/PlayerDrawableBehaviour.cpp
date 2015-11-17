#include "PlayerDrawableBehaviour.h"
#include "Entity.h"

PlayerDrawableBehaviour::PlayerDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : 
	DrawableBehaviour(renderer, screenwidth, screenheight)
{ }

PlayerDrawableBehaviour::~PlayerDrawableBehaviour()
{
	delete spritesObject;
}

void PlayerDrawableBehaviour::Draw()
{
	if (GetEntity()->GetEntityState() != currentState)
	{
		sprites = spritesObject->GetAnimationByState(GetEntity()->GetEntityState(), &angle);
		currentState = GetEntity()->GetEntityState();
		currentFrame = 0;
	}
	
	// Render current frame SCREEN SIZE NOT YET SET!!!
	
	float xpos = static_cast<float>((screenWidth / 2) - (screenWidth / 4));//( / Ratio) - (camera->GetX() / Ratio);
	float ypos = static_cast<float>(entity->GetYPos() / Ratio);// - (camera->GetY() / Ratio);

	SDL_Rect* currentClip = &sprites[currentFrame / sprites.size()];
	if (angle < 1)
		spriteSheetTexture->render(renderer, xpos, ypos, currentClip);
	else
		spriteSheetTexture->renderFlipVertical(renderer, xpos, ypos, currentClip, angle);

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / sprites.size() >= sprites.size())
	{
		currentFrame = 0;
		if (currentState == EntityState::WalkLeftStart || currentState == EntityState::WalkRightStart)
		{
			if (currentState == EntityState::WalkLeftStart)
				currentState = EntityState::WalkLeft;
			else
				currentState = EntityState::WalkRight;
		}
	}
}

void PlayerDrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{
	sprites = sdl_sprites;
}

bool PlayerDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	spritesheetPath = "";
	spritesheetName = "sprites.png";

	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, spritesheetPath + spritesheetName))
	{
		printf("Failed to load spritesheet! \n");
		success = false;
	}
	else
	{
		currentState = EntityState::None;
		spritesObject = new PlayerSpriteObject();
	}

	return success;
}

PlayerDrawableBehaviour* PlayerDrawableBehaviour::EmptyClone()
{
	return new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight);
}
