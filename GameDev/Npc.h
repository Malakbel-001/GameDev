#pragma once
#include "Actor.h"

class Npc :
	public Actor
{
private:
	int score;

public:
	Npc();
	
	virtual ~Npc();
	virtual Actor* EmptyClone();
	void setBody(b2Body* _body);
	b2Body* GetBody();

	void SetScore(int _score);
	int GetScore();
protected:
	
};

