#pragma once
#include "Box2D\Box2D.h"

class Entity
{
public:
	Entity();
	~Entity();
	virtual void Init(b2Body* _body);
	virtual Entity* EmptyClone();
	
private:
	b2Body* body;
};

