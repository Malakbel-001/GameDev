#pragma once
#include "Box2D\Box2D.h"

class Entity
{
	private:
		b2Body* body;

	public:
		Entity();
		virtual ~Entity();
		virtual void Init(b2Body* _body);
		virtual Entity* EmptyClone();
};
