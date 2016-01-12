#pragma once
#include <vector>
#include "Box2D\Box2D.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "GameStateManager.h"
#include "rapidxml-1.13\rapidxml.hpp"
#include "rapidxml-1.13\rapidxml_print.hpp"
#include "rapidxml-1.13\rapidxml_utils.hpp"
#include "LoadedLevel.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
class Level;
using namespace rapidxml;
class LevelFactory
{
public:
	static Level* GetNextLevel(Level*, PlayState* play);

	static Level* GetFirstLevel(PlayState* play);

	static Level* LoadLevel(BehaviourFactory* bf, std::string name);
	static Level* LoadLevel(PlayState* play, BehaviourFactory* bf, std::string name);

	static bool SaveLevel(Level* l,std::string name);

	static Level* GetSpecificLevel(PlayState* play, int lvl);
	static Level* GetSpecificLevel(int lvl);

	static void DeletePointers();

	static Level* GetEmptyLevel();
private:
	LevelFactory();
	~LevelFactory();

	static void Init();

	static std::vector<Level*> levels;
	
	static Level* GetLoadedLevel(PlayState* play, BehaviourFactory* bf, std::string name);
};

