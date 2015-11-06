#pragma once
#include "DrawableBehaviour.h"
class EnemyDrawableBehaviour :
	public DrawableBehaviour
{
public:
	

	const int IDLE_ANIMATION_FRAMES = 8;
	const int WALK_ANIMATION_FRAMES = 7;
	vector<SDL_Rect> idleSprites;
	vector<SDL_Rect> walkSprites;

public:
	EnemyDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight);
	~EnemyDrawableBehaviour();

	EnemyDrawableBehaviour* EmptyClone() override;

	void Draw() override;
	void SetSprites(vector<SDL_Rect> sdl_sprites) override;
	bool LoadMedia() override;
};

