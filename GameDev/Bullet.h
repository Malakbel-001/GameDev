#pragma once
#include "Actor.h"
class Bullet :
	public Actor
{
public:
	Bullet();
	virtual ~Bullet();


	virtual Bullet* EmptyClone();
	void SetBody(b2Body* _body);
	
	b2Body* GetBody();


};

