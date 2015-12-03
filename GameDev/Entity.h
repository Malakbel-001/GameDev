#pragma once
#include "Box2D\Box2D.h"

#include "BehaviourFactory.h"
#include "DrawableContainer.h"
#include "CollidableBehaviour.h"
#include "Object.h"

class Entity : public Object
{
	private:
	
	protected:
		float width;
		float height;
		b2Body* body;	
	
	public:
		Entity();
		virtual ~Entity();
		virtual void Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);
		virtual Entity* EmptyClone();
		virtual int GetWidth();
		virtual int GetHeight();
		virtual float GetXpos();
		virtual float GetYpos();
		virtual float GetAngle();
		virtual void SetScore(int _score);	//NPC needed method
		virtual int GetScore();				//NPC needed method

		b2Body* GetBody();
};
