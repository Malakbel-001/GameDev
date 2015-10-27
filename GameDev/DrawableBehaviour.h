#pragma once
#include <vector>
#include "SDL.h"
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

	void Draw(SDL_Renderer* renderer, LTexture* spriteSheetTexture);
	void SetSprites(vector<SDL_Rect> sdl_sprites);
private:
	vector<SDL_Rect> sprites;
	int currentFrame;
};

