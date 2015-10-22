#pragma once
#include "Box2D\Box2D.h"
class Level
{
private:

protected:
	int lvlWigth, lvlHeight;

public:
	Level(int _lvlWidth, int _lvlHeight);
	virtual ~Level();

	void setLvlWidth(int _lvlWidth);
	void setLvlHeight(int _lvlHeight);

	int getLvlWidth();
	int getLvlHeight();

	b2World* GetWorld();

private:
	
	b2World* world;

};

