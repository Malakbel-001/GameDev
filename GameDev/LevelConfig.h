#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
class LevelConfig
{
private:
	const char* levelsChar = "Resources/levels/levels.txt";
	map<string, bool>* levelsMap;
public:
	LevelConfig();
	~LevelConfig();

	void SaveLevelProgress(string);
	void LoadLevels();
	void ResetLevels();
	map<string, bool>* GetLevels();
};

