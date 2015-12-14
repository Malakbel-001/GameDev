#pragma once
#include "Player.h"
#include "SoundBank.h"
#include "BareEntity.h"

class EntityFactory;
class Weapon : public BareEntity
{
public:
	Weapon();
	~Weapon();
	void Init(float _xpos, float _ypos, float _angle, EntityState _state, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer);
	void Pickup(Actor* _actor, b2Vec2 _defaultShootingDirection);
	virtual void Shoot(EntityFactory* eF);
	virtual void AddAmmo(int ammo);
	void SetXVec(float x);
	void SetYVec(float y);
	b2Vec2 GetVec();
	virtual Weapon* EmptyClone();
	virtual float GetXpos();
	virtual float GetYpos();
	virtual float GetAngle();
	int GetAmmo();

protected:
	
	Actor* actor;
	int ammo;
	float fireSpeed;
	float timecounter;
	b2Vec2 vec;
	b2Vec2 defaultShootingDirection;
	int maxAmmo;



};

