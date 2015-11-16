#pragma once
#include "Actor.h"
#include "SoundBank.h"

class Player :
	public Actor
{
	private:
		// stuff

	protected:
		// stuff

	public:
		Player();
		virtual ~Player();
		void setBody(b2Body* _body);
		virtual Entity* EmptyClone();
		b2Body* GetBody();

		void HandleKeyEvents(SDL_Keycode _code);
};
