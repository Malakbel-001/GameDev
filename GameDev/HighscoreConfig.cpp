#include "HighscoreConfig.h"


HighscoreConfig::HighscoreConfig()
{
	highscores = new vector<Score>;
	LoadHighscore();
}

void HighscoreConfig::LoadHighscore(){
	highscores->clear();
	ifstream scoreStream;
	scoreStream.open(highscoreChar);
	stringstream ss;
	ss << scoreStream.rdbuf();
	string temp = "";
	int x = 0;
	while (getline(ss, temp, '|'))
	{
		std::stringstream aa;
		aa << temp;
		string temp2 = "";
		Score score;
		int y = 1;
		while (getline(aa, temp2, ',')){
			if (y == 1){
				score.SetName(temp2);
			}
			else if (y == 2){
				score.SetScore(temp2);
			}
			else if (y == 3){
				score.SetTimeMin(temp2);
			}
			else if (y == 4){
				score.SetTimeSec(temp2);
			}
			y++;
		}
		x++;
		highscores->push_back(score);
	}
}

void HighscoreConfig::SaveHighscore(string name, int score, string timeMin, string timeSec){
	string saveString = "|"+name+","+to_string(score)+","+timeMin+","+timeSec;
	ofstream outfile;
	outfile.open(highscoreChar, ios_base::app);
	outfile << saveString;
}

vector<Score>* HighscoreConfig::GetHighscore(){
	return highscores;
}


HighscoreConfig::~HighscoreConfig()
{
	//delete highscores;
}
