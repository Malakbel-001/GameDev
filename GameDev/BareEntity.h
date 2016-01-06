#pragma once
#include "Object.h"
class BareEntity :
	public Object
{
public:
	BareEntity();
	~BareEntity();
	virtual void Init(float _xpos, float _ypos, float _angle, EntityState _state, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer, MoveableContainer* moveContainer);

	virtual float GetXpos();
	virtual float GetYpos();
	virtual float GetAngle();
	virtual void SetXpos(float _xpos);
	virtual void SetYpos(float _ypos);
	virtual void SetAngle(float _angle);

protected:
	float xpos;
	float ypos;
	float angle;
};

