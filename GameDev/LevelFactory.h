#pragma once
#include "Box2D\Box2D.h"
#include "Level.h"
#include <vector>

class LevelFactory
{
public:
	

	static Level* GetNextLevel(Level*);
	static Level* GetFirstLevel();
private:
	LevelFactory();
	~LevelFactory();
	static void Init();
	static std::vector<Level*> levels;
	
};

