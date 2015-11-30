#pragma once
#include "Behaviour.h"
#include "Npc.h"
#include "EntityFactory.h"

class MoveableBehaviour :
	public Behaviour
{
public:
	MoveableBehaviour();
	virtual ~MoveableBehaviour();

	void SetEntity(Entity* _entity);
	Entity* GetEntity();

	void SetEntityFactory(EntityFactory* ef);

	virtual MoveableBehaviour* EmptyClone();
	virtual void Move();

protected:
	Entity* entity;
	EntityFactory* enf;
};


















