#pragma once
#include <iostream>
#include "Box2D\Box2D.h"
#include "BehaviourFactory.h"
#include "DrawableContainer.h"
#include "MoveableContainer.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, EntityFactory* ef, DrawableContainer* drawContainer, MoveableContainer* moveContainer);
	virtual Entity* EmptyClone();
	virtual int GetWidth();
	virtual int GetHeight();
	virtual int GetXPos();
	virtual int GetYPos();
	EntityState GetState();
	void SetState(EntityState _state);
	EntityType GetType();
	b2Body* GetBody();
	void Update();

protected:
	float width;
	float height;
	b2Body* body;
	DrawableBehaviour* draw;
	MoveableBehaviour* move;

	EntityType type;
	EntityState state;
};
