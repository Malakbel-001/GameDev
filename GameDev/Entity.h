#pragma once
#include "Box2D\Box2D.h"
#include "DrawableBehaviour.h"
#include "BehaviourFactory.h"
#include "DrawableContainer.h"

class Entity
{
	protected:
	b2Body* body;
	DrawableBehaviour* draw;
	EntityType type;
	private:
	
		float width;
		float height;
	public:
		Entity();
		virtual ~Entity();
		virtual void Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);
		virtual Entity* EmptyClone();
		virtual int GetWidth();
		virtual int GetHeight();
		virtual int GetXPos();
		virtual int GetYPos();
};
