#pragma once
#include "Actor.h"


class Player :
	public Actor
{

public:
	Player();
	virtual ~Player();
	void setBody(b2Body* _body);
	virtual Entity* EmptyClone();
	b2Body* GetBody();
};
