#pragma once
#include "Entity.h"
#include "ActorState.h"

class Weapon;

class Actor :
	public Entity
{
public:
	Actor();
	virtual ~Actor();
	virtual void InitActor(b2Body* _body, int _hitdmg, int _healt, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);

	
	virtual Actor* EmptyClone();
	virtual void SetHealt(int _healt);
	int GetHealt();
	int GetDamage();
	bool IsDead();
	virtual void SetDirection(b2Vec2 dir);
	virtual b2Vec2 GetDirection();
	virtual Weapon* GetCurrentWeapon();
	int GetJumpTimeOut();
	void SetJumpTimeOut(int m_jumpTimeout);
	int GetNumFootContacts();
	void SetNumFootContacts(int x);

protected:
	int numFootContacts;
	int m_jumpTimeout;
	b2Vec2 direction;
	Weapon* currentWep = nullptr;
	
private:
	bool dead;
	int health;
	int hitdmg;
	CollidableBehaviour* col;
	CollidableBehaviour* jumpsensor;
	ActorState* state;
};

