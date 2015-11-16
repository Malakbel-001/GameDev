#pragma once
#include <vector>
#include <SDL.h>
#include "EntityState.h"

class PlayerSpriteObject
{
	private:
		std::vector<SDL_Rect> idle;
		std::vector<SDL_Rect> walkStart;
		std::vector<SDL_Rect> walk;
		std::vector<SDL_Rect> crouch;
		std::vector<SDL_Rect> knife;
		std::vector<SDL_Rect> shoot;
		std::vector<SDL_Rect> jump;
		std::vector<SDL_Rect> jumpMove;

		std::vector<SDL_Rect> GetDefault();
		std::vector<SDL_Rect> GetIdle();
		std::vector<SDL_Rect> GetWalkStart();
		std::vector<SDL_Rect> GetWalk();
		std::vector<SDL_Rect> GetCrouch();
		std::vector<SDL_Rect> GetKnife();
		std::vector<SDL_Rect> GetShoot();
		std::vector<SDL_Rect> GetJump();
		std::vector<SDL_Rect> GetJumpMove();

	protected:
		// stuff

	public:
		PlayerSpriteObject();
		~PlayerSpriteObject();

		std::vector<SDL_Rect> GetAnimationByState(EntityState _state, double *angle);
};
