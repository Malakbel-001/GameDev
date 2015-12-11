#pragma once
#include "Behaviour.h"

class Object;

class MoveableBehaviour :
	public Behaviour
{
public:
	MoveableBehaviour();
	virtual ~MoveableBehaviour();

	void SetEntity(Object* _entity);
	Object* GetEntity();

	MoveableBehaviour* EmptyClone();

	virtual void Move(float dt);

protected:
	Object* entity;
};


















