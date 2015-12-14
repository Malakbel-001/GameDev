#pragma once
#include "EntityState.h"
#include <vector>
#include <SDL.h>
#include "LTexture.h"


class Sprite
{
public:
	Sprite(SDL_Renderer* _renderer);
	~Sprite();

	SDL_Rect* GetAnimationFrame(EntityState state, int frame);
	void SetAnimationSet(EntityState state);
	int GetAnimationSize(EntityState state);
	void SetRenderer(SDL_Renderer* _renderer);
	LTexture* GetSpritesheet();
	bool LoadMedia(std::string path);
	float GetXOffSet();
	float GetYOffSet();
	float GetFrameYOffSet(int frame);
	float GetFrameXOffSet(int frame);
protected:
	virtual void SetAnimations();
	std::vector<SDL_Rect>* currentSprites;
	LTexture* spriteSheetTexture;
	SDL_Renderer* renderer;
	float xOffSet;
	float yOffSet;

	int IDLE_ANIMATION_FRAMES;
	int WALK_ANIMATION_FRAMES;
	int JUMP_ANIMATION_FRAMES;
	int SHOOT_ANIMATION_FRAMES;
	int DYING_ANIMATION_FRAMES;
	int CURRENT_ANIMATION_FRAMES;
	SDL_Rect defaultSprite;
	std::vector<SDL_Rect>* idleSprites;
	std::vector<SDL_Rect>* walkSprites;
	std::vector<SDL_Rect>* dyingSprites;
	std::vector<float>* spriteXOffset;
	std::vector<float>* spriteYOffset;
};

