#pragma once
#include "Actor.h"
class Acorn :
	public Actor
{
public:
	Acorn();
	~Acorn();

	virtual Acorn* EmptyClone();
	void SetBody(b2Body* _body);

	b2Body* GetBody();
};

