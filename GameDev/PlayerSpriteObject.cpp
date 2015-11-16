#include "PlayerSpriteObject.h"


PlayerSpriteObject::PlayerSpriteObject()
{
	// idle animations
	idle.push_back(SDL_Rect{ 4, 0, 30, 40 });
	idle.push_back(SDL_Rect{ 34, 0, 30, 40 });
	idle.push_back(SDL_Rect{ 64, 0, 30, 40 });

	// waling start animations
	walkStart.push_back(SDL_Rect{ 107, 0, 31, 40 });
	walkStart.push_back(SDL_Rect{ 139, 1, 31, 40 });

	// walking animations
	walk.push_back(SDL_Rect{ 137, 0, 32, 41 });
	walk.push_back(SDL_Rect{ 201, 1, 32, 41 });
	walk.push_back(SDL_Rect{ 233, 0, 32, 41 });
	walk.push_back(SDL_Rect{ 264, 0, 32, 41 });
	walk.push_back(SDL_Rect{ 298, 0, 32, 41 });
	walk.push_back(SDL_Rect{ 330, 0, 36, 41 });
	walk.push_back(SDL_Rect{ 366, 0, 32, 41 });

	// crouch animations (missing ducking animation)
	crouch.push_back(SDL_Rect{ 330, 516, 34, 25 });
	crouch.push_back(SDL_Rect{ 363, 516, 34, 25 });
	crouch.push_back(SDL_Rect{ 264, 544, 34, 25 });
	crouch.push_back(SDL_Rect{ 298, 543, 34, 25 });

	// Shoot animations
	shoot.push_back(SDL_Rect{ 3, 59, 51, 37 });
	shoot.push_back(SDL_Rect{ 55, 59, 51, 37 });
	shoot.push_back(SDL_Rect{ 110, 59, 37, 37 });
	shoot.push_back(SDL_Rect{ 152, 57, 37, 39 }); // ?? check

	// Jump animation
	jump.push_back(SDL_Rect{ 3, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 32, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 63, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 94, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 124, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 156, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 187, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 218, 189, 29, 48 });
	jump.push_back(SDL_Rect{ 250, 189, 29, 48 });
}

PlayerSpriteObject::~PlayerSpriteObject() {}


std::vector<SDL_Rect> PlayerSpriteObject::GetAnimationByState(EntityState _state, double *angle)
{
	(_state > EntityState::EndLeftMovement) ? *angle = 180 : *angle = 0;

	#pragma region Switch Animations
	switch (_state)
	{
		case None:
			return this->GetDefault();
			break;

		case IdleLeft:
		case IdleRight:
			return this->GetIdle();
			break;

		case WalkLleftStart:
		case WalkRightStart:
			return this->GetWalkStart();
			break;
		case WalkLleft:
		case WalkRight:
			return this->GetWalk();
			break;
		case CrouchLeft:
		case CrouchRight:
			return this->GetCrouch();
			break;
		case ShootLeft:
		case ShootRight:
			return this->GetShoot();
			break;
		case JumpLeft:
		case JumpRight:
			return this->GetJump();
			break;
		case JumpLeftMove:
		case JumpRightMove:
			return this->GetJumpMove();
			break;
		case EndLeftMovement:
		case EndRightMovement:
			return this->GetDefault();
			break;
		default:
			return this->GetDefault();
			break;
	}
	#pragma endregion

	return this->GetDefault();
}

#pragma region Get animations
std::vector<SDL_Rect> PlayerSpriteObject::GetDefault()
{
	return this->GetIdle();
}

std::vector<SDL_Rect> PlayerSpriteObject::GetIdle()
{
	return this->idle;
}

std::vector<SDL_Rect> PlayerSpriteObject::GetWalkStart()
{
	return this->walkStart;
}

std::vector<SDL_Rect> PlayerSpriteObject::GetWalk()
{
	return this->walk;
}

std::vector<SDL_Rect> PlayerSpriteObject::GetCrouch()
{
	return this->crouch;
}

std::vector<SDL_Rect> PlayerSpriteObject::GetShoot()
{
	return this->shoot;
}

std::vector<SDL_Rect> PlayerSpriteObject::GetJump()
{
	return this->jump;
}

std::vector<SDL_Rect> PlayerSpriteObject::GetJumpMove()
{
	return this->GetDefault();
}
#pragma endregion
