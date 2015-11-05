#include "LevelFactory.h"

std::vector<Level*> LevelFactory::levels;
LevelFactory::LevelFactory() { }
	
LevelFactory::~LevelFactory() { }

void LevelFactory::Init()
{
<<<<<<< HEAD
	levels = {
		new testLevel(10000, 10000), 
		//TODO add , new Level1() , new level2()
=======
	levels = { new TestLevel(100, 100)
	//	//TODO add , new Level1() , new level2()

>>>>>>> refs/remotes/origin/Develop
	};
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
	bool foundLevel = false;
	for (size_t i = 0; i < levels.size(); i++)
	{
		if (foundLevel){
			
			return levels[i];
		}
		if (levels[i] == level)
			foundLevel = true;
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
