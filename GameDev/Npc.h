#pragma once
#include "Actor.h"

class EntityFactory;
class Npc :
	public Actor
{

public:
	Npc(EntityFactory* _factory);
	
	virtual ~Npc();
	virtual Actor* EmptyClone();
	void setBody(b2Body* _body);
	b2Body* GetBody();

	void SetScore(int _score);
	int GetScore();

	virtual void SetHealth(int _health);

	EntityFactory* GetFactory();

	void SetVehicle(Npc* _vehicle);
	Npc* GetVehicle();
protected:
	Npc* vehicle;
	int score;
	EntityFactory* factory;
};

