#pragma once
#include "Behaviour.h"

class Entity;

class MoveableBehaviour :
	public Behaviour
{
public:
	MoveableBehaviour();
	virtual ~MoveableBehaviour();

	void SetEntity(Entity* _entity);

	MoveableBehaviour* EmptyClone();

	virtual void Move();

protected:
	Entity* entity;
};


















