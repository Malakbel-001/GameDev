#pragma once
#include "Actor.h"

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
		virtual Actor* EmptyClone();
		b2Body* GetBody();

};
