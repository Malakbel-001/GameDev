#pragma once
#include "Box2D\Box2D.h"

class Entity
{
	protected:
	b2Body* body;
	private:
	
		float width;
		float height;
	public:
		Entity();
		virtual ~Entity();
		virtual void Init(b2Body* _body, float _width, float _height);
		virtual Entity* EmptyClone();
};
