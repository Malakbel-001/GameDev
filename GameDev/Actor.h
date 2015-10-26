#pragma once
#include "Entity.h"
#include "ActorState.h"
class Actor :
	public Entity
{
public:
	Actor();
	virtual ~Actor();

	void SetState(ActorState* new_state);

	ActorState* GetState();

private:
	ActorState* state;
};

