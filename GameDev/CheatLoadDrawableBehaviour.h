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
		CheatLoadDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
		~CheatLoadDrawableBehaviour();

		CheatLoadDrawableBehaviour* EmptyClone() override;

		void Draw() override;
		virtual void CycleFrames(bool cycle) override;

};