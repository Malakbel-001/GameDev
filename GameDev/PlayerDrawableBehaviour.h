#pragma once
#include "DrawableBehaviour.h"
#include "Camera.h"
#include "EntityState.h"
#include "PlayerSpriteObject.h"

class PlayerDrawableBehaviour :
	public DrawableBehaviour
{
	private:
		Camera* camera;
		EntityState currentState;
		double angle;
		PlayerSpriteObject* spritesObject;
		
		const int IDLE_ANIMATION_FRAMES = 3;
		const int WALK_ANIMATION_FRAMES = 7;
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
