#include "LevelFactory.h"

std::vector<Level*> LevelFactory::levels;
LevelFactory::LevelFactory() { }
	
LevelFactory::~LevelFactory() { }

void LevelFactory::Init()
{
	//levels = { new testLevel()
	//	//TODO add , new Level1() , new level2()

	//};
}

Level* LevelFactory::GetFirstLevel()
{
	if (!(levels.size() > 0))
	{
		Init();
	}
	return levels[0];
}

Level* LevelFactory::GetNextLevel(Level* level)
{
	if (!(levels.size() > 0))
	{
		Init();
	}
	int x = 0;
	bool foundLevel = false;
	while (levels.size() > x)
	{
		if (foundLevel)
			return levels[x];

		if (levels[x] == level)
			foundLevel = true;

		x++;
	}
	if (foundLevel)
	{
		// you just finished last level
		// give te first level
		//TODO back to main screen
		return levels[0];
	}
	//level was not in levels list get te first level
	return levels[0];
}
