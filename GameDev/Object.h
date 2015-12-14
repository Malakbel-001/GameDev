#pragma once
#include "EntityState.h"
#include "BehaviourFactory.h"
#include "DrawableContainer.h"

class Object
{
public:
	Object();
	~Object();
	virtual void Init(EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);
	virtual float GetXpos() = 0;
	virtual float GetYpos() = 0;
	virtual float GetAngle() = 0;
	virtual EntityState GetState();
	virtual void SetState(EntityState _state);
	EntityType GetType();
	virtual bool ShouldDraw();
	void SetShouldDraw(bool _shoulddraw);
	void SetFlipped(bool _flipped);
	bool GetFlipped();
protected:
	bool shouldDraw = true;
	DrawableBehaviour* draw;
	EntityType type;
	EntityState state;
	bool flipped;
};

