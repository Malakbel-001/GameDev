#pragma once
#include "DrawableBehaviour.h"

class CheatLoadDrawableBehaviour :
	public DrawableBehaviour {
	private:
		Camera* camera;
		const int IDLE_ANIMATION_FRAMES = 3;
		const int WALK_ANIMATION_FRAMES = 7;
		vector<SDL_Rect> idleSprites;
		vector<SDL_Rect> walkSprites;

	public:
		CheatLoadDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight);
		~CheatLoadDrawableBehaviour();

		CheatLoadDrawableBehaviour* EmptyClone() override;

		void Draw() override;
		void SetSprites(vector<SDL_Rect> sdl_sprites) override;
		bool LoadMedia() override;

};