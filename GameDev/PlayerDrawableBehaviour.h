#pragma once
#include "SDL.h"
#include "LTexture.h"
#include "DrawableBehaviour.h"
class PlayerDrawableBehaviour :
	public DrawableBehaviour
{
public:
	PlayerDrawableBehaviour(SDL_Renderer* sdl_renderer) : DrawableBehaviour(sdl_renderer);
	~PlayerDrawableBehaviour();

	void Init();
	void Draw();
	bool LoadMedia();	
private:
	SDL_Surface* spriteSheet = NULL;
	LTexture spriteSheetTexture;

	const int IDLE_ANIMATION_FRAMES = 3;
	const int WALK_ANIMATION_FRAMES = 9;
	SDL_Rect idleSprites[3];
	SDL_Rect walkSprites[9];
};

