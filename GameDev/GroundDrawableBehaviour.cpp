#include "GroundDrawableBehaviour.h"
#include "Entity.h"


GroundDrawableBehaviour::GroundDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
	LoadMedia();
}


GroundDrawableBehaviour::~GroundDrawableBehaviour()
{
}



void GroundDrawableBehaviour::Draw()
{

		spriteSheetTexture->render(renderer, entity->GetXPos(), entity->GetYPos(), &sprites);
		
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
		sprites.y = 100;
		sprites.w = 255;
		sprites.h = 130;
	}
	return success;
}

GroundDrawableBehaviour* GroundDrawableBehaviour::EmptyClone()
{
	return new GroundDrawableBehaviour(renderer, screenWidth, screenHeight);
}