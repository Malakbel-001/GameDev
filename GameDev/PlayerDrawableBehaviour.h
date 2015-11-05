#pragma once
#include "DrawableBehaviour.h"
#include "Camera.h"

class PlayerDrawableBehaviour :
	public DrawableBehaviour
{
	private:
		Camera* camera;
		const int IDLE_ANIMATION_FRAMES = 3;
		const int WALK_ANIMATION_FRAMES = 9;
		vector<SDL_Rect> idleSprites;
		vector<SDL_Rect> walkSprites;

	public:
		PlayerDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight);
		~PlayerDrawableBehaviour();

		PlayerDrawableBehaviour* EmptyClone() override;

		void Draw() override;
		void SetSprites(vector<SDL_Rect> sdl_sprites) override;
		bool LoadMedia() override;
};