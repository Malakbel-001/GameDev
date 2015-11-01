#pragma once
#include <vector>
#include <SDL.h>
#include "Behaviour.h"
#include "LTexture.h"

using namespace std;
class DrawableBehaviour :
	public Behaviour
{
public:
	DrawableBehaviour();
	virtual ~DrawableBehaviour();

	DrawableBehaviour* EmptyClone();

	void Draw(SDL_Renderer* renderer);
	void SetSprites(vector<SDL_Rect> sdl_sprites);
	bool LoadMedia(SDL_Renderer* renderer);
private:
	vector<SDL_Rect> sprites;
	int currentFrame;

	SDL_Surface* spriteSheet = NULL;
	LTexture* spriteSheetTexture;

	const int IDLE_ANIMATION_FRAMES = 3;
	const int WALK_ANIMATION_FRAMES = 9;
	SDL_Rect idleSprites[3];
	SDL_Rect walkSprites[9];
};

