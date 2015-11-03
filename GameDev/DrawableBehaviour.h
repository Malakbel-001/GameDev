#pragma once
#include <vector>
#include <SDL.h>
#include "Behaviour.h"
#include "LTexture.h"
#include "Box2D\Box2D.h"


using namespace std;
class DrawableBehaviour :
	public Behaviour
{
public:
	b2Body* body;
	DrawableBehaviour();
	virtual ~DrawableBehaviour();

	virtual DrawableBehaviour* EmptyClone();

	virtual void Draw(SDL_Renderer* renderer);
	void SetSprites(vector<SDL_Rect> sdl_sprites);
	virtual bool LoadMedia(SDL_Renderer* renderer);
protected:
	vector<SDL_Rect> sprites;
	int currentFrame;

	SDL_Surface* spriteSheet = NULL;
	LTexture* spriteSheetTexture;

	const int IDLE_ANIMATION_FRAMES = 3;
	const int WALK_ANIMATION_FRAMES = 9;
	SDL_Rect idleSprites[3];
	SDL_Rect walkSprites[9];
};

