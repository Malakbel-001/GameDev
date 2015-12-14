#include "LevelConfig.h"

LevelConfig::LevelConfig()
{
	levelsMap = new map<string, bool>();
	LoadLevels();
}

void LevelConfig::LoadLevels(){
	levelsMap->clear();
	ifstream levels;
	levels.open(levelsChar);
	string line;
	if (levels.is_open()){
		while (getline(levels, line)){
			istringstream is_line(line);
			string key;
			if (getline(is_line, key, '=')){
				string value;
				if (getline(is_line, value)){
					if (value.size() != 1 || value[0] < '0' || value[0] > '1') { //error handling value/bool
						cout << "Error, couldn't read value" << endl;
						//no console though, throw exception error?
					}
					else {
						bool booleanValue = (value[0] == '1');
						levelsMap->insert(make_pair(key, booleanValue));
					}
				}
			}
		}
	}
	else {
		cout << "Unable to open file/settings" << endl;
	}
	//return levelsMap;
}

void LevelConfig::SaveLevelProgress(string s){
	ofstream levels;
	levels.open(levelsChar);
	for (auto it = levelsMap->begin(); it != levelsMap->end(); it++){
		if (it->first == s){
			levels << it->first << "=" << '1' << endl;
		}
		levels << it->first << "=" << it->second << endl;
	}
	levels.close();
}

void LevelConfig::ResetLevels(){
	ofstream levels;
	levels.open(levelsChar);
	for (auto it = levelsMap->begin(); it != levelsMap->end(); it++){
		if (it->first == "Level1"){
			levels << it->first << "=" << '1' << endl;
		}
		else {
			levels << it->first << "=" << '0' << endl;
		}
	}
	levels.close();
}

map<string, bool>* LevelConfig::GetLevels(){
	return levelsMap;
}

LevelConfig::~LevelConfig()
{
}
