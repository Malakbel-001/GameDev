#pragma once
#include "Box2D\Box2D.h"
#include "DrawableBehaviour.h"
#include "BehaviourFactory.h"
#include "DrawableContainer.h"
#include "CollidableBehaviour.h"

class Entity
{
	private:
	
	protected:
		float width;
		float height;
		b2Body* body;
		DrawableBehaviour* draw;
		
		EntityType type;
		EntityState state;
	
	public:
		Entity();
		virtual ~Entity();
		virtual void Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);
		virtual Entity* EmptyClone();
		virtual int GetWidth();
		virtual int GetHeight();
		virtual int GetXPos();
		virtual int GetYPos();
		virtual EntityState GetState();
		virtual void SetState(EntityState _state); 
		EntityType GetType();
		b2Body* GetBody();
};
