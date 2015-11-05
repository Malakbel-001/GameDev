#pragma once
#include <iostream>

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
		virtual Entity* EmptyClone();
		b2Body* GetBody();
};
