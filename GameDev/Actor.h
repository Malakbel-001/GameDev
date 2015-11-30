#pragma once
#include "Entity.h"
#include "Shotgun.h"

class Actor :
	public Entity
{
public:
	Actor();
	virtual ~Actor();
	virtual void InitActor(b2Body* _body, int _hitdmg, int _healt, float _width, float _height, EntityType _type, BehaviourFactory* bf, EntityFactory* ef, DrawableContainer* drawContainer, MoveableContainer* moveContainer);

	
	virtual Actor* EmptyClone();
	virtual void SetHealt(int _healt);
	int GetHealt();
	int GetDamage();
	bool IsDead();	
	virtual void SetDirection(b2Vec2 dir);
	virtual b2Vec2 GetDirection();
	Weapon* GetCurrentWeapon();

protected:
	b2Vec2 direction;
	Weapon* currentWep = nullptr;

private:
	bool dead;
	int health;
	int hitdmg;
	CollidableBehaviour* col;
};

