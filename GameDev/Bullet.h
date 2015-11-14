#pragma once
#include "Actor.h"
class Bullet :
	public Actor
{
public:
	Bullet();
	virtual ~Bullet();

	virtual Actor* EmptyClone();
	void setBody(b2Body* _body);
	b2Body* GetBody();
	
};

