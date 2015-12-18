#include "Score.h"


Score::Score()
{
	time.resize(2);
}

void Score::SetName(string name){
	this->name = name;
}

void Score::SetScore(string score){
	this->score = atoi(score.c_str());
}

void Score::SetTimeMin(string time){
	this->time.at(0) = time;
}

void Score::SetTimeSec(string time){
	this->time.at(1) = time;
}

string Score::GetName(){
	return name;
}

int Score::GetScore(){
	return score;
}

vector<string> Score::GetTime(){
	return time;
}


Score::~Score()
{
}
