#pragma once
#include "DrawableBehaviour.h"
#include "Camera.h"

class PlayerDrawableBehaviour :
	public DrawableBehaviour
{
	private:
		Camera* camera;

	public:
		PlayerDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
		~PlayerDrawableBehaviour();

		PlayerDrawableBehaviour* EmptyClone() override;

		void Draw() override;
};