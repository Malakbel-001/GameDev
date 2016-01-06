#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include "Score.h"
using namespace std;
class HighscoreConfig
{
private:
	const char* highscoreChar = "Resources/highscore/highscore.txt";
	vector<Score>* highscores;
public:
	HighscoreConfig();
	~HighscoreConfig();

	void SaveHighscore(string name, int score, string timeMin, string timeSec);
	void LoadHighscore();
	vector<Score>* GetHighscore();
};

