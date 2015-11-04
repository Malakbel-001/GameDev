#include "GroundDrawableBehaviour.h"


GroundDrawableBehaviour::GroundDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
	LoadMedia();
}


GroundDrawableBehaviour::~GroundDrawableBehaviour()
{
}



void GroundDrawableBehaviour::Draw()
{
	int groundlength = 0;

	while (groundlength < screenWidth)
	{
		spriteSheetTexture->render(renderer, groundlength, screenHeight, &sprites);
		groundlength = groundlength + sprites.w;
	}	
}

void GroundDrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{

}

bool GroundDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	spritesheetPath = "";
	spritesheetName = "grass.png";

	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, spritesheetPath + spritesheetName))
	{
		printf("Failed to load spritesheet! \n");
		success = false;
	}
	else
	{
		sprites.x = 515;
		sprites.y = 280;
		sprites.w = 255;
		sprites.h = 255;
	}
	return success;
}

GroundDrawableBehaviour* GroundDrawableBehaviour::EmptyClone()
{
	return new GroundDrawableBehaviour(renderer, screenWidth, screenHeight);
}