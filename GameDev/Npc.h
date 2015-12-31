#pragma once
#include "Actor.h"

class EntityFactory;
class Npc :
	public Actor
{
private:
	int score;

public:
	Npc(EntityFactory* _factory);
	
	virtual ~Npc();
	virtual Actor* EmptyClone();
	void setBody(b2Body* _body);
	b2Body* GetBody();

	void SetScore(int _score);
	int GetScore();

	EntityFactory* GetFactory();
protected:

	EntityFactory* factory;
};

