#pragma once
#include <string>
#include <vector>
using namespace std;
class Score
{
private:
	string name;
	int score;
	vector<string> time;
public:
	Score();
	~Score();

	void SetName(string name);
	void SetScore(string score);
	void SetTimeMin(string time);
	void SetTimeSec(string time);

	string GetName();
	int GetScore();
	vector<string> GetTime();

	bool operator< (const Score &other) const {
		return score > other.score;
	}
};

