#pragma once
class Level
{
private:

protected:
	int lvlWigth, lvlHeight;

public:
	Level(int _lvlWidth, int _lvlHeight);
	virtual ~Level();

	void setLvlWidth(int _lvlWidth);
	void setLvlHeight(int _lvlHeight);

	int getLvlWidth();
	int getLvlHeight();
};

