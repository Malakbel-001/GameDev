#pragma once
#include "Box2D\Box2D.h"
#include "DrawableBehaviour.h"

class Entity
{
	private:
		

	public:
		b2Body* body;
		DrawableBehaviour draw;
		Entity();
		virtual ~Entity();
		virtual void Init(b2Body* _body);
		virtual Entity* EmptyClone();
		void HandleEvent(SDL_Event& e);
};
