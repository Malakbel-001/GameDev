#pragma once
#include <unordered_map>
#include "Behaviour.h"
#include "EntityState.h"

class Object;
class BaseCommand;
class MoveableBehaviour :
	public Behaviour
{
public:
	MoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands);
	virtual ~MoveableBehaviour();

	void SetEntity(Object* _entity);
	Object* GetEntity();

	MoveableBehaviour* EmptyClone();

	virtual void Move(float dt);

protected:
	Object* entity;
	std::unordered_map<EntityState, BaseCommand*> commands;
};


















