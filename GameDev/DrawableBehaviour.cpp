#include "DrawableBehaviour.h"


DrawableBehaviour::DrawableBehaviour(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight)
{
	renderer = sdl_renderer;
	screenWidth = screenwidth;
	screenHeight = screenheight;
	currentFrame = 0;	
	spriteSheetTexture = new LTexture();
}


DrawableBehaviour::~DrawableBehaviour()
{
}

DrawableBehaviour* DrawableBehaviour::EmptyClone()
{ 
	return nullptr; 
}

void DrawableBehaviour::Draw()
{
	//printf("Behaviour not initialized");
}

void DrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{
	//printf("Behaviour not initialized");
}

bool DrawableBehaviour::LoadMedia()
{
	//printf("Behaviour not initialized");
	return false;
}