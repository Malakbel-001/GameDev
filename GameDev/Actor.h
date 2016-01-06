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
	virtual void InitActor(b2Body* _body, int _hitdmg, int _health, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);

	
	virtual Actor* EmptyClone();
	virtual void SetHealth(int _health);
	int GetHealth();
	int GetMaxHealth();
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
	CollidableBehaviour* col;
	
private:
	bool dead;
	int health;
	int maxHealth; //NEW
	int hitdmg;
	
	CollidableBehaviour* jumpsensor;
	ActorState* state;
};

