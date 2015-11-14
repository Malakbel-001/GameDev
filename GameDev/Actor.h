#pragma once
#include "Entity.h"
#include "ActorState.h"


class Actor :
	public Entity
{
public:
	Actor();
	virtual ~Actor();
	virtual void InitActor(b2Body* _body, int _hitdmg, int _healt, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);

	
	virtual Actor* EmptyClone();
	void SetState(ActorState* new_state);
	ActorState* GetState();
	virtual void SetHealt(int _healt);
	int GetHealt();
	int GetDamage();
	bool IsDead();
private:
	bool dead;
	int healt;
	int hitdmg;
	CollidableBehaviour* col;
	ActorState* state;
};

