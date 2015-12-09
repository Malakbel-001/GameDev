#pragma once
#include "EntityState.h"
#include "BehaviourFactory.h"
#include "DrawableContainer.h"
#include "MoveableContainer.h"

class Object
{
public:
	Object();
	~Object();
	virtual void Init(EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer, MoveableContainer* moveContainer);
	virtual float GetXpos() = 0;
	virtual float GetYpos() = 0;
	virtual float GetAngle() = 0;
	virtual EntityState GetState();
	virtual void SetState(EntityState _state);
	EntityType GetType();
	virtual bool ShouldDraw();
	void SetShouldDraw(bool _shoulddraw);
protected:
	bool shouldDraw = true;
	DrawableBehaviour* draw;
	MoveableBehaviour* move;
	EntityType type;
	EntityState state;
};

